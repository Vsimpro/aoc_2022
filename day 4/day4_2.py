# AoC Day 4b
# In how many assignment pairs does one range fully contain the other?
total = 0
for elf_pair in [line.strip().split(",") for line in open("input.txt")]:
    first_elf =  elf_pair[0].split("-")
    second_elf = elf_pair[1].split("-")
    
    # Check for overlaps
    min_left = int(first_elf[0])
    max_left = int(first_elf[1])

    min_right = int(second_elf[0])
    max_right = int(second_elf[1])

    if (min_left <= max_right and max_left >= min_right):
        total += 1
    

print(total)