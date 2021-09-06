// chi.c
// ϴ�����

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"ϴ���"NOR);
        set("long", @LONG
����һ��ʯ��������С�أ��ഫ��ʱ���ʼ������Ĳ��Ĵ������������ÿ��
·���˵ر��ڳ���ϴ�󡣡����ҹ�¡����������������ɫ����ҹ����µ��գ���
��ӳ����У�ˮ��һɫ����ɫ��������һ�����к�Ⱥ��û��
LONG);
        set("outdoors", "������");
        setup();
}

void init()
{
        object me, room;

        me = this_player();
        room = load_object(__DIR__"xixiangchi2");
        if(interactive(me)){ 
                tell_room(environment(me), me->name()+"��ͨһ�����˽�����\n", ({ me }));
                tell_object(me, "����ͨһ�������˳�ˮ��\n");    
                tell_room(room, "ֻ������ͨ��һ����"+me->name()+"�Ѿ������˳�ˮ�\n");        
                call_out("do_swim", 1, me);     
        }
        add_action("do_no", "save");
        add_action("do_no", "quit");
        add_action("do_no", "practice");
        add_action("do_no", "respirate");
        add_action("do_no", "exercise");
        add_action("do_halt", "halt");
}

int do_no()
{
        write("��׼��\n");
        return 1;
}

int do_swim(object me)
{
        if (!me || !present(me) || !living(me)) return 0;       
        
        if(me->query_con() < 25){
                tell_object(me, HIB "���ϳ�ˮ����̹ǣ����͵�һ������æ�������⣡\n"NOR);
                tell_room(environment(me), me->name()+"ȫ����£�����ææ����������ȥ��\n", ({ me }));
                me->move(__DIR__"xixiangchi2");
                tell_room(environment(me), me->name()+"����ææ�ش�ϴ���������������ȫ���ף�ֱ����£�\n", ({ me }));
                me->add_busy(2);
                me->receive_damage("jingli", 100);
                me->receive_damage("qi", 100);
                me->receive_damage("jing", 100);
                return 1;
        }
        tell_object(me, GRN "���������ĳ�ˮ�о�����Ϸ�������㻹�ǵ���������·���߹���̽��\n"NOR);
        me->set_temp("swimming", 1);
        me->set_temp("pending/swimming",1);
        //me->set_temp("apply/short", ({me->short(1)+GRN" <��ˮ��>"NOR}));
        me->receive_damage("jingli", me->query("con") * 4 );
        call_out("do_pa", 20+random(40)-me->query_con(), me); 
        me->add_busy(1);
        return 1;        
}

int do_pa(object me)
{
        int i;

        if(!me || !present(me)) return 0;
        if(me->query_temp("looked")) me->delete_temp("apply/short");
        me->delete_temp("swimming");
        me->delete_temp("looked");
        me->delete_temp("pending/swimming");
        //me->delete_temp("apply/short");
        if(!living(me)){
                message_vision("һ����紵���������Ե�$N�Ƶ��رߡ�\n", me);
                me->move(__DIR__"xixiangchi2");
                message_vision("һ��������紵���������Ե�$N�Ƶ��˳رߡ�\n", me);
                return 1;
        }

        tell_object(me, HIY "\nͻȻһ����紵�����������һ�£���æ����ϴ��ء�\n" NOR );       
        tell_room(environment(me), "һ����紵����"+me->name()+"���������һ�£����ϳرߴ����·���\n", ({ me }));
        i = me->query("per")/2;
        me->improve_skill("beauty", me->query("con") * (i + random(i)));
        me->move(__DIR__"xixiangchi2");
        me->add_busy(1);
        tell_room(environment(me), me->name()+"�����ӵش�ϴ���������������\n", ({ me })); 
        return 1;
}

int do_halt()
{
        object me = this_player();

        if (me->is_busy())
                return notify_fail("����æ���ģ�\n");
//        remove_call_out("do_pa");
	if(me->query_temp("looked")) me->delete_temp("apply/short");
        me->delete_temp("swimming");
        me->delete_temp("looked");
        me->delete_temp("pending/swimming");
        //me->delete_temp("apply/short");
        if(me->query_temp("looked")){
                write(HIY "����æ�����·�������ϴ��ء�\n" NOR);
                tell_room(environment(me), me->name()+"�Ҵ�ææ����������ϳرߡ�\n", ({ me }));
                me->move(__DIR__"xixiangchi2");
                tell_room(environment(me), me->name()+"һ�������ܻ��ش�ϴ���������������\n", ({ me })); 
                return 1;
        }
        write(HIY "ͻȻ��������ʲô�£���æ���ϳرߴ����·���\n" NOR );
        tell_room(environment(me), me->name()+"����������ʲô�Ƶģ���æ���ϳرߴ����·���\n", ({ me }));
        me->move(__DIR__"xixiangchi2");
        tell_room(environment(me), me->name()+"����ææ�ش�ϴ���������������\n", ({ me })); 
        return 1;
}
