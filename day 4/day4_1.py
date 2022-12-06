# AoC Day 4a
# In how many assignment pairs does one range fully contain the other?
total = 0
for elf_pair in [line.strip().split(",") for line in open("input.txt")]:
    first_elf =  elf_pair[0].split("-")
    second_elf = elf_pair[1].split("-")
    
    if (int(first_elf[0]) <= int(second_elf[0]) and int(first_elf[1]) >= int(second_elf[1])
    or (int(second_elf[0]) <= int(first_elf[0]) and int(second_elf[1]) >= int(first_elf[1]))):
        total += 1

print(total)