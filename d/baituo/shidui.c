#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
����������Χȫ�Ǿ�ʯ���������������ҵ���ʯ�ӣ����Ǳ��˻����
ʯ������������顣����һ��ƽ������ʯ���϶���һֻѩ�׵ĸ�󡡣
LONG);        
        set("objects", ([
                    __DIR__"npc/chanchu" : 1,
                    BINGQI_D("gs-zhang") : 1,
        ]));
        set("item_desc", ([                    
                "stone": "\n��Щ��ʯ���а��棬���ó��Ǳ��������������õġ�\n",
        ]));
        set("outdoors", "����ɽ");
        setup(); 
}

void init()
{
       	object me = this_player();       
       	if(!me->query_temp("baituo_yun") 
       	&& me->query("id") != "xuanbing chanchu" 
       	&& me->query("id") != "snowman"
       	&& !me->query_skill("hamagong", 1) ){
             	message_vision(HIW"�������ͻȻ���𣬶���$Nһ�ڶ��������\n"NOR,this_player()); 
             	tell_object(me, HIB "��е�����һ�����Σ���ʱ���˹�ȥ��\n" NOR ); 
             	me->unconcious();
             	me->move(__DIR__"yuanzi5");
             	tell_room(environment(me), me->name()+"ͻȻ�Ӿ�ʯ֮��ֱ�����������ȡ���һ��ˤ�ڵ��ϣ�\n", ({ me }));
          	if(random(me->query_skill("poison", 1)) < 100 ) {
          		me->set_temp("last_damage_from", "�о綾��");
          		me->die();                   
          	}
          	
          	else me->add("max_neili", -5);
          	}  
        add_action("do_climb", "climb");
        add_action("do_climb", "pa");
        add_action("do_strike", "strike");       
}

int do_climb(string arg)
{
        object me = this_player();
        if( !arg || arg=="" ) return 0;
        
        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("����æ���ء�\n");
        	
        if (arg == "stone" ){   
           	message_vision("$N�ֽŲ��ã������˾�ʯȥ������һ�ݣ��Ѿ����˳�ȥ��\n", me);                      
               	me->move(__DIR__"yuanzi5");
               	message("vision", me->name() + "���������˳�����\n",environment(me), ({me}) );
               	me->start_busy(1);
               	if( !me->query_skill("hamabu", 1) && me->query_skill("hamagong", 1) ){
               		tell_object(me, "���ͷ�������Ծ������ƣ�������˸�󡲽������\n");
               		me->set_skill("hamabu", 1);
               	}
               	
               	return 1;
        }     
        return 0;
}

int do_strike(string arg)
{
        int improve, cost;
        object me = this_player();
        
        improve = me->query_int() / 10 + random(me->query_int() * 5 / 6);
        improve /= 2;
        if( !arg || arg=="" ) return 0;
        
        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("����æ���ء�\n");
        	
        if (arg == "stone" ){             
            	if(!me->query_skill("hamagong", 1))  
               		return notify_fail("������ָ�����ƾ�ʯ������¶��һ˿�ѿ�����ɫ��\n");
                if( me->query_skill("hamagong", 1) > 81 && me->query("oyf/hamagong") < 2)  
               		return notify_fail("������ָ�����ƾ�ʯ������¶��һ˿�ѿ�����ɫ��\n");
            	if( me->query_skill("hamagong", 1) > 100 )  
               		return notify_fail("��һ�����ʯ��ȥ��ֻ�����һ������ʯ��������������룡\n");
               		
                if( me->query_skill("hamagong", 1) == 100 && (me->query("oyf/hmg_add") < 1) ) {
                   message_vision(WHT"\n$Nһ�����ʯ��ȥ��ֻ�����һ������ʯ��$P����������룡\n"NOR, me);  
                	tell_object(me, "����һ�ƾ���ʮ�㣬�������Գ����ˣ�\n������ʮ�㣬��������˲��١�\n");
                	me->add("combat_exp", 30000);
                	me->add("max_neili", 300);
                	me->add("max_jingli", 200);
                	me->set_skill("hamagong", 110);
                	me->set_skill("force", me->query_skill("force", 1)+10);
                	log_file("quest/oyf_log", sprintf("%s(%s) �� %s ��ϰHMG��100�������õ�������\n", me->name(1), me->query("id"), ctime(time()) ) );
                	return 1;       
                }
                
        	cost = 600 / (int)me->query("int");
        	cost = 600 / (int)me->query("int");

           	if ((int)me->query("jingli") < cost || (int)me->query("jing") < cost){
                	message_vision("$N��������, һ�����������������$N���˹�ȥ��\n",me);
                	me->unconcious();
                	return 1;
                } 
                
                message_vision("$NĬ�и�󡹦�ھ���������˫��֮�ϣ�һ�������ʯ��ȥ��\n"NOR, me);  
           	me->improve_skill("hamagong", improve);            
           	me->improve_skill("strike", improve/2); 
           	me->receive_damage("jing", cost, "���Ĺ���");
           	me->receive_damage("neili", cost/2, "���Ĺ���");
           	me->receive_damage("jingli", cost, "���Ĺ���");                        
           	return 1;
        }     
        return 0;
}

int valid_leave(object me, string dir)
{        
       me->delete_temp("baituo_yun");       
       return ::valid_leave(me);
}
