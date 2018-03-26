l = list(range(1, 10))
print(l)

print("Minimum: {}".format(min(l)))
print("Maximum: {}".format(max(l)))

i = int(input('Hladany element? '))

if i in l:
    print('Najdene')
else:
    print('Nenajdene')
