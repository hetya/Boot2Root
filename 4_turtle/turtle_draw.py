import turtle


def execute_command(t: turtle.Turtle, command: str):
    command = command.strip().lower()

    if command.startswith("avance"):
        # Extract number
        n = int("".join(filter(str.isdigit, command)))
        t.forward(n)

    elif command.startswith("recule"):
        n = int("".join(filter(str.isdigit, command)))
        t.backward(n)

    elif "tourne droite" in command:
        n = int("".join(filter(str.isdigit, command)))
        t.right(n)

    elif "tourne gauche" in command:
        n = int("".join(filter(str.isdigit, command)))
        t.left(n)


def draw_from_file(filename: str):
    screen = turtle.Screen()
    t = turtle.Turtle()
    t.speed(1)

    # Read commands
    with open(filename, "r", encoding="utf-8") as f:
        for line in f:
            if line.strip():
                execute_command(t, line)

    screen.mainloop()


if __name__ == "__main__":
    draw_from_file("turtle")
