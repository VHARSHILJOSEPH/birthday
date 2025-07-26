<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Happy Birthday!</title>
  <style>
    body {
      margin: 0;
      font-family: 'Comic Sans MS', cursive;
      background: linear-gradient(#fff0f5, #ffe6f0);
      overflow: hidden;
      text-align: center;
    }
    h1 {
      margin-top: 20px;
      color: #ff4d94;
      font-size: 2.5rem;
      text-shadow: 2px 2px #fff;
    }
    .cats {
      display: flex;
      justify-content: center;
      gap: 20px;
      margin-top: 10px;
      flex-wrap: wrap;
    }
    .cats img {
      width: 130px;
      border-radius: 20px;
      box-shadow: 0 4px 8px rgba(0,0,0,0.2);
      animation: bounce 2s infinite;
      object-fit: cover;
    }
    @keyframes bounce {
      0%, 100% { transform: translateY(0); }
      50% { transform: translateY(-20px); }
    }
    canvas {
      position: fixed;
      top: 0;
      left: 0;
      pointer-events: none;
    }
    button {
      margin-top: 30px;
      padding: 15px 30px;
      background: #ff80bf;
      border: none;
      border-radius: 25px;
      color: white;
      font-size: 1.2rem;
      cursor: pointer;
      box-shadow: 0 4px 8px rgba(0,0,0,0.3);
      transition: transform 0.2s;
    }
    button:hover {
      transform: scale(1.1);
    }
    .card-container {
      perspective: 1000px;
      margin-top: 30px;
      display: flex;
      justify-content: center;
    }
    .card {
      width: 300px;
      height: 200px;
      position: relative;
      transform-style: preserve-3d;
      transition: transform 1s;
    }
    .card.open {
      transform: rotateY(180deg);
    }
    .card-side {
      position: absolute;
      width: 100%;
      height: 100%;
      backface-visibility: hidden;
      border-radius: 15px;
      box-shadow: 0 4px 10px rgba(0,0,0,0.3);
      display: flex;
      align-items: center;
      justify-content: center;
      font-size: 1.5rem;
      color: #fff;
      padding: 20px;
      text-align: center;
    }
    .card-front {
      background: #ffb3d9;
    }
    .card-back {
      background: #ff4d94;
      transform: rotateY(180deg);
    }
  </style>
</head>
<body>
  <h1>🎂 Meow! Happy Birthday Jahitha! 🎂</h1>

  <div class="cats">
    <img src="kitten1.jpg" alt="Cat 1">
    <img src="kitten2.jpg" alt="Cat 2">
    <img src="kitten3.jpg" alt="Cat 3">
  </div>

  <button onclick="openCard()">Open Birthday Card 🎁</button>

  <div class="card-container">
    <div class="card" id="birthdayCard">
      <div class="card-side card-front">
        Click the button to open!
      </div>
      <div class="card-side card-back">
        🎉 Happy Birthday Jahitha! 🎉<br>
        May your day be as cute as these cats! 🐾
      </div>
    </div>
  </div>

  <canvas id="confetti"></canvas>

  <!-- Background Music -->
  <audio autoplay loop>
    <source src="https://cdn.pixabay.com/download/audio/2022/03/15/audio_f6b36f19d7.mp3?filename=happy-birthday-to-you-15884.mp3" type="audio/mpeg">
  </audio>

  <script>
    function openCard() {
      document.getElementById("birthdayCard").classList.toggle("open");
    }

    const canvas = document.getElementById('confetti');
    const ctx = canvas.getContext('2d');
    let W = window.innerWidth;
    let H = window.innerHeight;
    canvas.width = W;
    canvas.height = H;

    let confetti = Array.from({ length: 150 }, () => ({
      x: Math.random() * W,
      y: Math.random() * H,
      r: Math.random() * 6 + 4,
      d: Math.random() * 100,
      color: `hsl(${Math.random() * 360}, 100%, 70%)`,
      tilt: Math.random() * 10 - 10
    }));

    function draw() {
      ctx.clearRect(0, 0, W, H);
      confetti.forEach(c => {
        ctx.beginPath();
        ctx.fillStyle = c.color;
        ctx.fillRect(c.x, c.y, c.r, c.r);
      });
      update();
    }

    function update() {
      confetti.forEach(c => {
        c.y += Math.cos(c.d) + 1 + c.r / 2;
        c.x += Math.sin(c.d);
        if (c.y > H) {
          c.y = 0; 
          c.x = Math.random() * W;
        }
      });
    }

    setInterval(draw, 20);
  </script>
</body>
</html>