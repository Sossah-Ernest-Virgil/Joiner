import time
import os

# ==============================
# Load balances from file if exists
# ==============================
balances = {
    "Ernest": 1000000000000,
    "Richmond": 10000000000,
    "Gustave": 10000000,
    "Lordina": 10000
}

file_name = "bank_data.txt"

def load_balances():
    if os.path.exists(file_name):
        with open(file_name, "r") as f:
            for line in f:
                name, bal = line.strip().split(":")
                balances[name] = float(bal)

def save_balances():
    with open(file_name, "w") as f:
        for name, bal in balances.items():
            f.write(f"{name}:{bal}\n")

# ==============================
# User credentials
# ==============================
users = {
    "Ernest":   {"id": "0976", "password": "Woods"},
    "Richmond": {"id": "6789", "password": "Richy_1"},
    "Gustave":  {"id": "1245", "password": "Lamya"},
    "Lordina":  {"id": "5431", "password": "1234"}
}

# Load existing balances
load_balances()

# ==============================
# Main Program Loop
# ==============================
while True:
    print("""
====================================
WELCOME TO SOSSAH INTERNATIONAL BANK
WE GIVE YOU SPECIAL SERVICES 24/7.
====================================
OPTIONS:
1 - DEPOSIT
2 - WITHDRAW
3 - CHECK BALANCE
4 - BACK TO OPTIONS
5 - EXIT
====================================
""")

    user = input("Enter your Username:\n")
    if user not in users:
        print("❌ Wrong username! Try again.")
        continue

    ID = input("Enter your bank Identification number:\n")
    if ID != users[user]["id"]:
        print("❌ Invalid ID. Try again later.")
        continue

    # ==============================
    # Password with increasing wait
    # ==============================
    wait_time = 10
    while True:
        pwd = input("Enter password:\n")
        if pwd == users[user]["password"]:
            print(f"✅ Hello {user}, Welcome ❤\n")
            break
        else:
            print(f"❌ Wrong password! Try again in {wait_time} seconds.")
            for i in range(wait_time, 0, -1):
                print(f"⏳ Waiting... {i}s", end="\r")
                time.sleep(1)
            print()
            wait_time += 5

    # ==============================
    # Banking Operations
    # ==============================
    while True:
        try:
            option = int(input("Enter option:\n"))
        except ValueError:
            print("Invalid input! Enter a number.")
            continue

        if option == 1:  # Deposit
            amount = float(input("Enter amount to deposit:\n"))
            balances[user] += amount
            save_balances()
            print(f"Current Balance = ${balances[user]}")
            print("Transaction successful ✅")
            break

        elif option == 2:  # Withdraw
            amount = float(input("Enter amount to withdraw:\n"))
            if amount > balances[user]:
                print("❌ Insufficient funds!")
            else:
                balances[user] -= amount
                save_balances()
                print(f"Current Balance = ${balances[user]}")
            break

        elif option == 3:  # Check Balance
            print(f"Your Current Balance = ${balances[user]}")
            break

        elif option == 4:  # Back to menu
            break

        elif option == 5:  # Exit
            print("Exiting... Thank you for banking with us ❤")
            exit()

        else:
            print("❌ Invalid operation! Try again.")
