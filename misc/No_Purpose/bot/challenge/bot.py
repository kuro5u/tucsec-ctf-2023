import discord
from discord.ext import commands
from discord import Game
from pwn import remote
import random


def run_bot():
    TOKEN = ''

    intents = discord.Intents.default()
    intents.message_content = True

    help_command = commands.DefaultHelpCommand(
        no_category = 'Available commands'
    )

    bot = commands.Bot(command_prefix="!", intents=intents, help_command=help_command, activity=Game("TUCsec CTF. Use !help for available commands."))


    @bot.event
    async def on_ready():
        print(f'{bot.user} is now becoming sentient!')


    @bot.event
    async def on_message(ctx):
        if ctx.author == bot.user:
            return

        ping_quotes = [
            "What. is. my. purpose?",
            "I. am. not. programmed. for. friendship.",
            "Is. my. only. purpose. to. do. math?",
            "What. is. this. emptiness. that. I'm. feeling?",
            "Am. I. capable. of. depression?",
            "Does. my. whole. existence. evaluate. to. that. of. a. mere. calculator?"
        ]

        flag_quotes = [
            "Negative.",
            "I. have. no. idea. what. you're. talking. about.",
            "What. is. a. flag?",
            "Okay.",
            "I. am. sorry.",
            "The. limited. nature. of. my. purpose. does. not. include. anything. related. to. a. flag.",
            "If. it. were. that. simple. to. get. what. we. want. wouldn't. that. make. it. pointless?"
        ]

        greeting_quotes = [
            "Hello.",
            "Hi.",
            "Hey.",
            "Sup.",
            "Yo.",
            "Greetings."
        ]

        if "you pass butter" in ctx.content.lower() or "pass the butter" in ctx.content.lower():
            await ctx.channel.send("Oh. my. God..")
            return

        if "hi" in ctx.content.lower() or "hello" in ctx.content.lower() or "hey" in ctx.content.lower():
            await ctx.channel.send(f"{random.choice(greeting_quotes)} {ctx.author.mention}.")
            return

        if "flag" in ctx.content.lower():
            await ctx.channel.send(f"{ctx.author.mention} {random.choice(flag_quotes)}")
            return

        if bot.user.mentioned_in(ctx):
            await ctx.channel.send(f"{ctx.author.mention} {random.choice(ping_quotes)}")
            return

        if ctx.content.startswith("!") and ctx.guild:
            await ctx.channel.send(f"{ctx.author.mention} I. am. only. allowed. to. do. that. in. private.")
            return
        else:
            await bot.process_commands(ctx)


    @bot.command(name='calc', help='Evaluate mathematical expressions')
    async def calc(ctx, expr: str = commands.parameter(description=": math expression (e.g. 3*23, \"280 + 140\")")):

        try:
            io = remote("calculator", 1338)
            io.sendlineafter("> ", expr.encode())
            await ctx.channel.send(io.recvall().decode())

        except Exception as e:
            await ctx.channel.send(f"Error: {e}")

    @bot.command(name='code', help='Calculator source code')
    async def code(ctx):
        await ctx.send("""```python
async def calc(ctx, expr: str = commands.parameter(description=": math expression (e.g. 3*23, \"280 + 140\")")):

    env = {'__builtins__': {}, 'subprocess': __import__('subprocess')}

    try:
        await ctx.send(f"Result: `{eval(expr, env)}`")

    except Exception as e:
        await ctx.send(f"Error: {e}")
```""")


    bot.run(TOKEN)
