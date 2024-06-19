package com.restaurantManage.restaurantManage.DAO;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;

public interface GuestDAO extends JpaRepository<Guest,GuestId> {
    @Query(value = "SELECT 客人到来有返回值(?1, ?2)", nativeQuery = true)
    int guestCome(int numberOfGuests, int seatRequirement);

    @Query(value = "SELECT 查看前方排队人数(?1)",nativeQuery = true)
    int getPeopleQuantityBefore(int id);

    @Query(value = "select 桌号 from 来客 where 编号=?1 and 日期=curdate()",nativeQuery = true)
    String getTableIdByGuestID(int id);

    @Query(value = "SELECT 收银记录.金额 FROM 收银记录 WHERE 收银记录.来客_日期 = curdate() AND 收银记录.来客_编号 = ?1",nativeQuery = true)
    float getMoneyByGuestID(int id);

    @Query(value = "SELECT 收银记录.支付方式 FROM 收银记录 WHERE 收银记录.来客_日期 = curdate() AND 收银记录.来客_编号 = ?1",nativeQuery = true)
    String getMeasureByGuestID(int id);
}
