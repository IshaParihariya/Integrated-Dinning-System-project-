const menuItems = [
  { name: "Pizza", price: 200 },
  { name: "Burger", price: 150 },
  { name: "Pasta", price: 180 },
  { name: "Cold Drink", price: 50 },
  { name: "Ice Cream", price: 100 }
];

const menuDiv = document.getElementById("menu");

menuItems.forEach((item, index) => {
  menuDiv.innerHTML += `
    <div>
      <input type="checkbox" id="item${index}" value="${item.price}">
      <label for="item${index}">${item.name} - ₹${item.price}</label>
    </div>
  `;
});

document.getElementById("orderBtn").addEventListener("click", () => {
  let total = 0;
  menuItems.forEach((_, i) => {
    const checkbox = document.getElementById(`item${i}`);
    if (checkbox.checked) total += parseInt(checkbox.value);
  });
  document.getElementById("result").textContent = `Your total bill: ₹${total}`;
});
