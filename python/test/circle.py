import math

def inCircle(flag_lat, flag_lng, lat, lng):
    earth_radius = 6370996.81

    rad_lat_a = math.radians(flag_lat)
    rad_lng_a = math.radians(flag_lng)

    rad_lat_b = math.radians(lat)
    rad_lng_b = math.radians(lng)

    lng_sub = rad_lng_b - rad_lng_a
    lat_sub = rad_lat_b - rad_lat_a

    tmp = math.pow(math.sin(lat_sub / 2), 2) + math.cos(rad_lat_a) * math.cos(rad_lng_b) * math.pow(math.sin(lng_sub / 2), 2);
    distance = 2 * math.asin(min(1, math.sqrt(tmp))) * earth_radius

    return distance


def main():
    lat1, lng1, lat2, lng2 = map(float, input('Two address:').split())
    print(inCircle(lat1, lng1, lat2, lng2))

main()
