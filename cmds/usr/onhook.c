//onhook.c 闭关

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
	int time,pot,tb,exp,flag;
	
	object link_ob;

	seteuid(getuid());

  time = uptime()-me->query_temp("time"); //本次在线时间
    pot= me->query("qn_balance");            //潜能银行  
    tb = me->query("SJ_Credit");                 //通宝


if( !objectp(link_ob = me->query_temp("link_ob")) )
          return notify_fail("你不是经由正常连线进入，不能执行这个指令，请退出后再试。\n");



if(!arg || (arg!="halt" && arg!="over")) {
	
	if(me->query("on_hook"))
		
          return notify_fail("你闭关潜修状态尚未解除，请先使用onhook halt/over来结束潜修状态。\n");


exp = ((me->query("combat_exp") - me->query_temp("combat_exp"))/time ) * 2/3; // 每秒正常收益的2/3,要扣除潜修所得。

if(exp<1)
	     return notify_fail("你本次稳定在线时间实战收益效率过低，闭关潜修得不到多少经验的。\n");
	
/*	

if( !environment(me)->query("onhook_room") ) 
                        return notify_fail("此处不安全，无法闭关潜修，请返回帮派或门派驻地。\n");


if(time<3600)
        return notify_fail("你本次稳定在线时间不足一个小时，尚无法计算你的稳定收益数据。\n");
*/

if(pot<time*3)
      	return notify_fail("本次闭关预计消耗"+ time*3 +"点潜能，你保存的潜能不足以支持你闭关潜修的消耗。\n");

if(tb<time/36)
      	return notify_fail("你本次闭关潜修需要预备的生存资金为"+ time/36 + "个通宝，你的通宝似乎不够用了。\n");
	
//开始潜修。
	
	if( (int)link_ob->save() && (int)me->save() ) {
   write("\n\n你盘膝坐下，参照本门心法，潜运内息，进入了一种玄之又玄的闭关状态。\n\n");


    me->start_busy(99999);
    me->set("on_hook/start",time());  //开始时间。 
    me->set("on_hook/time",time()+ time*2);//预期潜修结束时间。 
    me->set("on_hook/pexp",exp);
    me->apply_condition("onhook",time/5+1);
          
     write(HIG"你本次闭关潜修最长时间为"+ CHINESE_D->chinese_time(time*2)+ "。\n"NOR);  
     write(HIG"预计消耗潜能"HIR+ time*3 + HIG"点，书剑通宝"HIR+ time/36 +HIG"枚。\n"NOR); 
     write(HIG"预计收益为实战经验"HIR +  exp*time*2 + HIG"点（"+exp*3600+"/小时）。\n"NOR);  
     write(HIG"当潜修结束时，你可以使用来"HIR"onhook over"HIG"结束潜修并领取收益。\n"NOR);  
     write(HIG"你也可以随时使用"HIR"onhook halt"HIG"来结束潜修并结算收益。\n"NOR);        
     write(HBRED"你现在可以关闭你的mud窗口了。\n\n\n\n"NOR);
   me->set_temp("block_msg/all",1);
      
   return 1;
   }
 }
  
 if(arg=="over" || arg=="halt"){
 	
 	if(!me->query("on_hook"))
 		        return notify_fail("你并没有进行闭关潜修啊。\n");
 
 	flag = 0;

if(time()-me->query("on_hook/time")>0) {
	   time= me->query("on_hook/time") -me->query("on_hook/start"); //潜修时间已过。
  flag =1;                                      
                                        }
else time = time() - me->query("on_hook/start");//潜修中断	

     me->clear_condition("onhook");
	   me->start_busy(-1);
	   me->delete_temp("block_msg");
     me->set_temp("time",uptime());

if(time<10) {
	
     write(HIG"你本次闭关潜修时间过短，没有获得任何收益。\n"NOR);  
	   me->delete("on_hook");
	   me->set_temp("combat_exp",me->query("combat_exp"));    
	   return 1;
	}

exp = time * me->query("on_hook/pexp");
tb = time/72;
pot = time*1.5;

me->add("combat_exp",exp);
me->add("qn_balance",-pot);
me->add("SJ_Credit",-tb);
me->delete("on_hook");
me->set_temp("combat_exp",me->query("combat_exp"));    
me->set_temp("onhook_exp",exp);
  
  if(flag==0)         
     write(HIG"\n\n你中断了闭关潜修。\n\n"NOR);  
     write(HIG"\n你本次闭关潜修持续时间为"+ CHINESE_D->chinese_time(time)+ "。\n"NOR);  
     write(HIG"消耗潜能"HIR+ pot + HIG"点，书剑通宝"HIR+ tb +HIG"枚。\n"NOR); 
     write(HIG"恭喜您，本次潜修您增加了"HIR +  exp + HIG"点实战经验（"+exp*3600/time +"/小时）。\n"NOR);
     write(HBRED"你现在可以开始游戏了。\n\n"NOR);
     return 1;
 	
 	}
 
   
	return notify_fail("你现在无法闭关练功。\n");
   
}

int help(object me)
{
	write(@HELP
指令格式：onhook [halt/over]

闭关潜修相关指令。

HELP
	);
	return 1;
}
