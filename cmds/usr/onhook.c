//onhook.c �չ�

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
	int time,pot,tb,exp,flag;
	
	object link_ob;

	seteuid(getuid());

  time = uptime()-me->query_temp("time"); //��������ʱ��
    pot= me->query("qn_balance");            //Ǳ������  
    tb = me->query("SJ_Credit");                 //ͨ��


if( !objectp(link_ob = me->query_temp("link_ob")) )
          return notify_fail("�㲻�Ǿ����������߽��룬����ִ�����ָ����˳������ԡ�\n");



if(!arg || (arg!="halt" && arg!="over")) {
	
	if(me->query("on_hook"))
		
          return notify_fail("��չ�Ǳ��״̬��δ���������ʹ��onhook halt/over������Ǳ��״̬��\n");


exp = ((me->query("combat_exp") - me->query_temp("combat_exp"))/time ) * 2/3; // ÿ�����������2/3,Ҫ�۳�Ǳ�����á�

if(exp<1)
	     return notify_fail("�㱾���ȶ�����ʱ��ʵս����Ч�ʹ��ͣ��չ�Ǳ�޵ò������پ���ġ�\n");
	
/*	

if( !environment(me)->query("onhook_room") ) 
                        return notify_fail("�˴�����ȫ���޷��չ�Ǳ�ޣ��뷵�ذ��ɻ�����פ�ء�\n");


if(time<3600)
        return notify_fail("�㱾���ȶ�����ʱ�䲻��һ��Сʱ�����޷���������ȶ��������ݡ�\n");
*/

if(pot<time*3)
      	return notify_fail("���αչ�Ԥ������"+ time*3 +"��Ǳ�ܣ��㱣���Ǳ�ܲ�����֧����չ�Ǳ�޵����ġ�\n");

if(tb<time/36)
      	return notify_fail("�㱾�αչ�Ǳ����ҪԤ���������ʽ�Ϊ"+ time/36 + "��ͨ�������ͨ���ƺ��������ˡ�\n");
	
//��ʼǱ�ޡ�
	
	if( (int)link_ob->save() && (int)me->save() ) {
   write("\n\n����ϥ���£����ձ����ķ���Ǳ����Ϣ��������һ����֮�����ıչ�״̬��\n\n");


    me->start_busy(99999);
    me->set("on_hook/start",time());  //��ʼʱ�䡣 
    me->set("on_hook/time",time()+ time*2);//Ԥ��Ǳ�޽���ʱ�䡣 
    me->set("on_hook/pexp",exp);
    me->apply_condition("onhook",time/5+1);
          
     write(HIG"�㱾�αչ�Ǳ���ʱ��Ϊ"+ CHINESE_D->chinese_time(time*2)+ "��\n"NOR);  
     write(HIG"Ԥ������Ǳ��"HIR+ time*3 + HIG"�㣬�齣ͨ��"HIR+ time/36 +HIG"ö��\n"NOR); 
     write(HIG"Ԥ������Ϊʵս����"HIR +  exp*time*2 + HIG"�㣨"+exp*3600+"/Сʱ����\n"NOR);  
     write(HIG"��Ǳ�޽���ʱ�������ʹ����"HIR"onhook over"HIG"����Ǳ�޲���ȡ���档\n"NOR);  
     write(HIG"��Ҳ������ʱʹ��"HIR"onhook halt"HIG"������Ǳ�޲��������档\n"NOR);        
     write(HBRED"�����ڿ��Թر����mud�����ˡ�\n\n\n\n"NOR);
   me->set_temp("block_msg/all",1);
      
   return 1;
   }
 }
  
 if(arg=="over" || arg=="halt"){
 	
 	if(!me->query("on_hook"))
 		        return notify_fail("�㲢û�н��бչ�Ǳ�ް���\n");
 
 	flag = 0;

if(time()-me->query("on_hook/time")>0) {
	   time= me->query("on_hook/time") -me->query("on_hook/start"); //Ǳ��ʱ���ѹ���
  flag =1;                                      
                                        }
else time = time() - me->query("on_hook/start");//Ǳ���ж�	

     me->clear_condition("onhook");
	   me->start_busy(-1);
	   me->delete_temp("block_msg");
     me->set_temp("time",uptime());

if(time<10) {
	
     write(HIG"�㱾�αչ�Ǳ��ʱ����̣�û�л���κ����档\n"NOR);  
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
     write(HIG"\n\n���ж��˱չ�Ǳ�ޡ�\n\n"NOR);  
     write(HIG"\n�㱾�αչ�Ǳ�޳���ʱ��Ϊ"+ CHINESE_D->chinese_time(time)+ "��\n"NOR);  
     write(HIG"����Ǳ��"HIR+ pot + HIG"�㣬�齣ͨ��"HIR+ tb +HIG"ö��\n"NOR); 
     write(HIG"��ϲ��������Ǳ����������"HIR +  exp + HIG"��ʵս���飨"+exp*3600/time +"/Сʱ����\n"NOR);
     write(HBRED"�����ڿ��Կ�ʼ��Ϸ�ˡ�\n\n"NOR);
     return 1;
 	
 	}
 
   
	return notify_fail("�������޷��չ�������\n");
   
}

int help(object me)
{
	write(@HELP
ָ���ʽ��onhook [halt/over]

�չ�Ǳ�����ָ�

HELP
	);
	return 1;
}
