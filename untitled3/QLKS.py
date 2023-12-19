class KhachSan:
    def __init__(self):
        self.khachHang = {}
        self.phong = {}

    def themKhachHang(self, id, ten):
        self.khachHang[id] = ten

    def xemKhachHang(self):
        for id, ten in self.khachHang.items():
            print(f"ID: {id}, Tên: {ten}")

    def xoaKhachHang(self, id):
        if id in self.khachHang:
            del self.khachHang[id]

    def themPhong(self, soPhong, loaiPhong):
        self.phong[soPhong] = loaiPhong

    def xemPhong(self):
        for soPhong, loaiPhong in self.phong.items():
            print(f"Số phòng: {soPhong}, Loại phòng: {loaiPhong}")

    def xoaPhong(self, soPhong):
        if soPhong in self.phong:
            del self.phong[soPhong]


ks = KhachSan()
ks.themKhachHang(1, 'Nguyen Van A')
ks.themKhachHang(2, 'Tran Thi B')
ks.xemKhachHang()
ks.xoaKhachHang(1)
ks.xemKhachHang()

ks.themPhong(101, 'Phòng đơn')
ks.themPhong(102, 'Phòng đôi')
ks.xemPhong()
ks.xoaPhong(101)
ks.xemPhong()
