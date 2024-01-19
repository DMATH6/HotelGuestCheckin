

class QuestDataBlock {       // The class
  public:
                 // Access specifier
struct {
  enum title {mr, ms, mrs};
  std::string title;
  std::string firstName;
  std::string lastName;
  enum paymentType {paypal, credit, bankTransfer, cryto};
  std::string phoneNumber;

  //hotelroomdata
  enum roomFloor {floorone_1, floortwo_2, floorthree_3, floorfour_4, floorfive_5, floorsix_6, floorseven_7, flooreight_8, floornine_9, floorten_10};
  enum roomNumber {roomone_1, roomtwo_2, roomthree_3, roomfour_4, roomfive_5, roomsix_6, roomseven_7, roomeight_8, roomnine_9, roomten_10, roomeleven_11, roomtwelve_12};

  enum guestStatus {booked, checkedIn, checkedOut};
  enum packageType {regular, vip, delux, gold};
  std::string otherGuestNames;
  std::string notes;

} GuestData;


};
