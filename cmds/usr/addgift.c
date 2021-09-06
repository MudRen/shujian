//Create by jpei 2010
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    int gifts, max_gifts;
    string gifts_name;

    max_gifts = me->query("relife/gifts/now");

    if(!arg){
        tell_object(me,"您可以使用“"+HIG+"addgift 天赋点数 to 天赋中文名称"+NOR+"”进行天赋分配!\n"NOR);
        tell_object(me,"您也可以使用“"+HIG+"addgift 天赋点数 to 声望"+NOR+"”将天赋永久转换为江湖声望!\n\n"NOR); 
        write("四项天赋的中文名称为“"HIW"膂力"NOR"”“"HIY"根骨"NOR"”“"HIM"身法"NOR"”“"HIC"悟性"NOR"”。 \n"NOR);
        write("江湖声望的中文名称为“"HIW"声望"NOR"”，英文代号为“"HIM"mana"NOR"”。 \n\n"NOR);
        write("江湖声望的用途：1、用以提升相关的天赋树。2、用以降低相应的Quest难度系数。 \n\n"NOR);
        return 1;
    }

    if(!sscanf(arg, "%d to %s", gifts, gifts_name)){
        tell_object(me,"请使用“addgift 天赋点数 to 天赋中文名称”进行分配！\n"NOR);
        write("四项天赋的中文名称为“膂力”“根骨”“身法”“悟性”。 \n"NOR);
        return 1;
    }
    else{
        if(gifts<1)
            return notify_fail("你脑子参悟过头坏掉了？\n");

        if(gifts > max_gifts)
            return notify_fail("你现在没这么多天赋点数可以分配！\n请用score指令来查看你现在拥有多少可分配天赋点数！\n");
//膂力
        if(gifts_name == "膂力" || gifts_name == "臂力" || gifts_name == "str" ){
               if((int)me->query("str",1)> 50 - gifts)
               return notify_fail("单项天赋最多不能超过50点！请重新选择！\n"NOR);
           
               me->add("str",gifts);
               me->add("relife/gifts/now",-gifts);
               me->add("relife/gifts/used",gifts);
               tell_object(me,"你将"+HIW+chinese_number(gifts)+NOR+"点天赋分配到了“"+HIR+"膂力"+NOR+"”上！\n");
               return 1;
        }

 
//根骨
        if(gifts_name == "根骨"|| gifts_name == "con"){
            if((int)me->query("con",1)>50 - gifts)
               return notify_fail("单项天赋最多不能超过50点！请重新选择！\n"NOR);
            me->add("con",gifts);
            me->add("relife/gifts/now",-gifts);
            me->add("relife/gifts/used",gifts);
            tell_object(me,"你将"+HIW+chinese_number(gifts)+NOR+"点天赋分配到了“"+HIR+"根骨"+NOR+"”上！\n");
            return 1;
        }
//身法
        if(gifts_name == "身法" || gifts_name == "dex"){
            if((int)me->query("dex",1)>50 - gifts)
               return notify_fail("单项天赋最多不能超过50点！请重新选择！\n"NOR);
            me->add("dex",gifts);
            me->add("relife/gifts/now",-gifts);
            me->add("relife/gifts/used",gifts);
            tell_object(me,"你将"+HIW+chinese_number(gifts)+NOR+"点天赋分配到了“"+HIR+"身法"+NOR+"”上！\n");
            return 1;
        }


//悟性
        if(gifts_name == "悟性" ||gifts_name == "int"){
            if((int)me->query("int",1)>50 - gifts)
               return notify_fail("单项天赋最多不能超过50点！请重新选择！\n"NOR);
            me->add("int",gifts);
            me->add("relife/gifts/now",-gifts);
            me->add("relife/gifts/used",gifts);
            tell_object(me,"你将"+HIW+chinese_number(gifts)+NOR+"点天赋分配到了“"+HIR+"悟性"+NOR+"”上！\n");
            return 1;
        }
        
//声望
        if(gifts_name == "声望" ||gifts_name == "mana"){
        	
            if(gifts > me->query("relife/gifts/total"))
               return notify_fail("请妥善分配您的四维天赋后再来提升您的江湖声望！\n"NOR);
        	
            me->add("mana",gifts*100);
            me->add("relife/gifts/now",-gifts);            
            me->add("relife/gifts/total",-gifts);
            tell_object(me,"你耗费了"+HIW+chinese_number(gifts)+NOR+"点参悟所得，获得了"+HIW+chinese_number(gifts*100)+NOR+"点“"+HIR+"江湖声望"+NOR+"”！\n");
            return 1;
        }
        //输错参数
        return notify_fail("请选择正确的天赋名称来添加天赋点数，指令格式：\n"+HIR+"giftadd 天赋点数 to 天赋中文名称 "+NOR+"!\n");
         }
        return 1;
}
