package com.restaurantManage.restaurantManage.Controller;

import com.restaurantManage.restaurantManage.DAO.theTable;
import com.restaurantManage.restaurantManage.service.GuestService;
import com.restaurantManage.restaurantManage.service.theTableService;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;

import java.util.List;

@Controller
public class TableController {
    private final theTableService theTableService;
    private final GuestService guestService;

    public TableController(theTableService theTableService,GuestService guestService){
        this.theTableService = theTableService;
        this.guestService = guestService;
    }


    @GetMapping("/{id}/tables")
    public String tables(Model model1, @PathVariable int id){

        // 获取所有桌子信息
        List<theTable> tables = theTableService.getAllTable();

        // 将顾客编号和桌子信息传递到HTML页面
        model1.addAttribute("customerNumber", id);
        model1.addAttribute("tables", tables);

        return "tables";
    }

    @GetMapping("/selectTable/{id}&{tableId}")
    public String selectTable(@PathVariable int id, @PathVariable String tableId){
        // 在此处添加逻辑以处理选择桌子的操作，例如更新桌子的状态

        theTableService.selectTable(id,tableId);
        return "redirect:/" + tableId + "/menu"; // 处理完成后重定向到tables页面
    }

    @GetMapping("/queue/{guestCount}&{seatCount}")
    public String queue(@PathVariable int guestCount, @PathVariable int seatCount) {
        // 调用服务层方法，并传递参数
        int id = guestService.guestCome(guestCount, seatCount);
        return "redirect:/" + id + "/tables";
    }

    @GetMapping("/queue")
    public String queue(){
        return "queue";
    }

}
