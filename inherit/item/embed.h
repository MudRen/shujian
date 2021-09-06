// embed.c
#include <ansi.h>

int do_embed(object me)
{
    	object ob;
    	ob = this_object();
  
    	if( !ob->query("embedded") || !me) return 0;
    
    	if(environment(ob) != me 
       	|| me->is_ghost() 
       	|| !me->query_temp("embed")){
       		tell_room(environment(me), "�Ŷ��\n" , ({ me }));  
            	delete("embedded");
              	return 0;
        }
        
    	me->receive_wound("qi", ob->query("damage"), "����"+ob->name()+"��");
        tell_object(me, HIR "��Ѫ��˳�������ϵ�"+ob->name()+HIR"�����વ�ֱ��������\n" NOR );
        tell_room(environment(me), HIR + "��Ѫ˳��"+me->name()+HIR"���ϵ�"+ob->name()+HIR"ֱ��������\n" NOR, ({ me }));  
        call_out("do_embed", 15+random(10), me);
        
    	return 1;
}
