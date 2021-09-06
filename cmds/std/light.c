// light.c
// by snowman@SJ 02/04/1999.

#include <ansi.h>

int main(object me, string arg)
{
    object obj, env;
    
    if (me->is_busy() || me->is_fighting()) return notify_fail("����æ���ء�\n");

    if(!arg) return notify_fail("��Ҫ��ȼʲô������\n");
    	     
    if(!objectp(obj = present(arg, me)) )
             if(!objectp(obj = present(arg, environment(me))))
    	            return notify_fail("�⡣���������û�ⶫ���ɣ�\n");
   
    if(!obj->query("light")) 
                    return notify_fail("��ȼ"+obj->name()+"�����ǲ����ۻ��ˣ�\n");
    if( !obj->query("light/time")) 
                    return notify_fail(obj->name()+"�Ѿ�ȼ���꣬���������ˡ�\n");    
                
    env = environment(me);
    if( !env ) return notify_fail("������ʲô�ط���\n");
    
    if( !present("fire", me))
             return notify_fail("��û�л��֣���ô��ȼ"+obj->name()+"�أ�\n");
             
    if(!obj->query("light/on")){
             if((string)obj->query("light/on_msg"))
	             message_vision(obj->query("light/on_msg"), me, obj);
             else message_vision("$N������ۣ���ž����һ�´�ȼ����$n���š�\n", me, obj);

             obj->set("light/on", 1);   // turn it on now.
             obj->set("no_put", 1);
             obj->fire_decay();
             
             if((env->query("no_light")  // some special rooms.
             || (env->query("outdoors") && NATURE_D->is_night()))  // night in open air.
             && !env->query_night_light()){
    	             env->light_up();   // light up the room.
                     env->set_temp("light_id", obj); 
                     obj->set("light/env", file_name(env));
                     }
             }
    else {
    	     if((string)obj->query("light/off_msg"))
	             message_vision(obj->query("light/off_msg"), me, obj);
             else message_vision("$N��$nҡ��ҡ�����콫�������ˡ�\n", me, obj);

             obj->delete("light/on");   // turn it off now.
             obj->set("light/time", obj->query("light/time"));
             
             if((string)obj->query("light/env")){
                  if(!env = find_object(obj->query("light/env")))
                       env = load_object(obj->query("light/env"));
                  if( env->query_temp("light_id") == obj){
    	               env->light_gone();   // turn light off in the room.
                       env->delete_temp("light_id");
                       }
                  }
             } 
    return 1;
}



int help(object me)
{
    write(@HELP
ָ���ʽ : light [��Ʒ����]
 
���ָ����������ȼĳ��������������Ʒ��

����
    light denglong  ��ȼ������
    light denglong  ���ѵ�ȼ�ĵ��������
    
HELP
    );
    return 1;
}
 
