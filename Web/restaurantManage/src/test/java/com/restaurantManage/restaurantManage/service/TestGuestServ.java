package com.restaurantManage.restaurantManage.service;


import com.restaurantManage.restaurantManage.DAO.GuestDAO;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;
import org.springframework.beans.factory.annotation.Autowired;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.mockito.ArgumentMatchers.anyInt;
import static org.mockito.Mockito.*;

@ExtendWith(MockitoExtension.class)
public class TestGuestServ {


    @Mock
    private GuestDAO guestDAO;
    @InjectMocks
    private GuestServiceImpl guestService;


    @Test
    public void testGuestCome(){

        when(guestDAO.guestCome(anyInt(), anyInt())).thenReturn(1);

        //条件覆盖
        assertThrows(IllegalArgumentException.class,()->guestService.guestCome(-1,1));

        assertThrows(IllegalArgumentException.class,()->guestService.guestCome(1,-1));

        // 调用被测试的方法
        int result = guestService.guestCome(1,1);

        // 验证 dishOrderDao.orderDish() 方法被调用
        verify(guestDAO, times(1)).guestCome(1,1);
        assertEquals(1,result);
    }
}
