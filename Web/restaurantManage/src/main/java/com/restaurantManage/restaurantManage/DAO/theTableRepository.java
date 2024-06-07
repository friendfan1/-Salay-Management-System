package com.restaurantManage.restaurantManage.DAO;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.jpa.repository.query.Procedure;
import org.springframework.data.repository.query.Param;

public interface theTableRepository extends JpaRepository<theTable, String> {
    @Procedure(value = "客人上桌")
    void guestToTable(@Param("param1")int guestNum, @Param("param2")String tableId);
}
