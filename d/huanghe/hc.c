
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���������̽�����һ�Һ�����
���ڳ��踻�����������ź��ĵ�ձ�����ϰ������ϸ�㣬�����������֮
�ҵĻ���һ�㡣
LONG
);
        set("no_fight",1);
        //set("sleep_room",1);
        //set("outdoors", "������");
        set_temp("curstatus","ready");
        setup();
}

void init()
{
        object me = this_player();
        mapping myfam;
        myfam = (mapping)me->query("family");
        if(!myfam || myfam["family_name"] != "������") {
        	message_vision("ͻȻ�и��˷���һ�Ű�$N���˳�ȥ��\n",me);
        	me->move(__DIR__"road2");
        	tell_object(environment(me),me->name()+"���˴Ӻ���������������\n",({me}));
        	return;
       	}  
        if(userp(me)) {
                call_out("run_mufa", 5+random(5),me);
        }
}

void run_mufa(object me)
{        
        if(!me){
        	destruct(this_object());
        	return;
        }
        message_vision(HIC"\n\n$N�����ϴ�����������ȥ���ۼ�������ӿ���Ƶ����գ���ֻ��Ÿ���Ӳ����衣\n"NOR,me);
        call_out("run_mufa1", 5+random(5), me);
}

void run_mufa1(object me)
{        
        if(!me){
        	destruct(this_object());
        	return;
        }
        message_vision(CYN"\n\n�˿̺����������󴬼�����ʻ��Ƭ�̹����$N���ں��涫����������һ��½�ء�\n"NOR,me);
        call_out("run_mufa2", 5+random(5), me);
}

void run_mufa2(object me)
{        
        if(!me){
        	destruct(this_object());
        	return;
        }
        message_vision(WHT"\n\nת�ۼ����Ȼʻ��½�أ�����������ľ�Դ䣬�����ĺ�̲��������ͷ������ѩ��ϸɳ��\n"NOR, me);
        call_out("run_mufa3", 4+random(5), me);
}

void run_mufa3(object me)
{
        object* ob;
        if(!me){
        	destruct(this_object());
        	return;
        }
        message_vision("����������ꑵأ�$N���������¹ڱ㻺��������ȥ��\n",me);
        ob = all_inventory(this_object());
        for(int i=0; i<sizeof(ob); i++) {
                if(!living(ob[i])) continue;
                ob[i]->move("/d/sld/dukou");
                tell_room(environment(me), ob[i]->name() + "�Ӻ���������������\n",({ ob[i] }));  
        }
        destruct(this_object());
}