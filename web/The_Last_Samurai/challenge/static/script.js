const imageContainer = document.getElementById('image-container');

document.addEventListener('mousemove', (e) => {
    const mouseX = e.clientX / window.innerWidth - 0.5;
    const mouseY = e.clientY / window.innerHeight - 0.5;

    const tiltAmount = 15;

    const transformValue = `perspective(1000px) rotateX(${-tiltAmount * mouseY}deg) rotateY(${tiltAmount * mouseX}deg)`;
    
    imageContainer.style.transform = transformValue;

});
