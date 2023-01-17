def citycountry (city,country,population=''):
    if population:
        result = f'{city},{country} - Population {population}'
    else:
        result = f"{city},{country}"
    print(result.title())
    return result.title()

