// Room: /u/jpei/thd/tomb.c
// Modified by Numa 19990906

#include <ansi.h>
inherit ROOM;

string* msg = ({
        "��",
        "��",
        "��",
        "��",
});

string* msg1 = ({
        "��æ",
        "��æ",
        "��æ",
        "����ææ",
        "�Ҵ�ææ",
});

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
���İ��ĸ�̨�������߳�����ֻ���̲������м���һƬ��ɫ����,
���ص���������һ���׻��ѳɵ�С�����׻�֮����һ�鶫���߸�¡
���߽��˲ŷ�����һ��ʯ�أ���ǰ��һ��Ĺ��(mubei)��
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"taohua1",
                "west" : __DIR__"taohua1",
                "south" : __DIR__"taohua1",
                "north" : __DIR__"taohua1",
        ]) );
        set("item_desc",([
                "mubei" : RED"
                        
                       ������
                       ���ҩ�
                       ������
                       ������
                       ��Ů��
                       ������
                       ���멦
                       ���ϩ�
                       ����
                       ���㩦
                       ��֮��
                       ��ڣ��
                       ������\n
"NOR
        ]) );
        set("no_clean_up", 0);
        set("outdoors","�һ���");

        setup();
}

void init()
{
        object me = this_player();
        
        if (me->query_temp("thd/job"))
                call_out("do_job",1,me);
                
        add_action("do_bai", "bai");
        add_action("do_bai", "guibai");
        add_action("do_bai", "gui");
        add_action("do_bai", "kneel");
        add_action("do_push","push");
        add_action("do_push","tui");
}

int do_bai(string arg)
{
        object me = this_player();

        if (arg != "mubei")
                return notify_fail("��Ҫ��ʲô��\n");
        
        message_vision("$N�ڷ�ǰ�򵹣����������ذ����İݡ�\n", me);
        me->set_temp("tomb/kneel", 1);
        return 1;
}

int do_push(string arg)
{
        string dir;
        object me = this_player();
        
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���أ�\n");

        if (!me->query_temp("tomb/kneel"))
                return notify_fail("ͻȻ,��Ĺ�г��һ����Ĺ����,��ݺݵĵ�����һ��.\n");
        if (!arg || arg=="")
                return notify_fail("ʲô?\n");
        if( arg=="mubei")
        {
                write("��Ҫ�����ĸ�����\n");
                return 1;
        }
        
        else if (sscanf(arg,"mubei %s",dir)==1)
        {
                if (dir=="left" || dir=="zuo")
                {
                        me->add_temp("tomb/p_left",1);
                        write("���Ĺ�������������ȥ�������ˡ���֨����������\n");
                        return 1;
                }
        
                else if (dir=="right" || dir=="you")
                {
                        me->add_temp("tomb/p_right",1);
                        write("���Ĺ���������ұ���ȥ�������ˡ���֨����������\n");
                        if ((int)me->query_temp("tomb/p_left")==3
                        &&  (int)me->query_temp("tomb/p_right")==3)
                        {
                                write("Ĺ�������ƿ���¶��һ��ʯ���ĵص������æ���˽�ȥ��\n");
                                message("vision", "Ĺ�������߻����ƿ���" + me->name() + "�첽���˽�ȥ��Ĺ���ֺ�£�����ˡ�\n", this_object(), me);
                                me->delete_temp("tomb/p_left");
                                me->delete_temp("tomb/p_right");
                                me->move(__DIR__"mudao1");
                                message("vision", me->name() + "�򿪰��ţ����˽�����\n", environment(me), me);
                        }
                        return 1;
                }
                else {write("��Ҫ�����ĸ�����?\n");return 1;}
        }
        else {write("��Ҫ��ʲô?\n");return 1;}
}


int valid_leave(object me,string dir)
{        
       me->delete_temp("tomb/p_left");
       me->delete_temp("tomb/p_right");
       me->delete_temp("tomb/kneel");
       return ::valid_leave(me,dir);
}

void do_job(object me)
{
        object ob;
        string p_id;
        tell_object(me,"����˵�꣬��" + msg1[random(sizeof(msg1))] +"���뿪�ˡ�\n");
        tell_object(me,HIR"ͻȻ����" + msg[random(sizeof(msg))] + "�ߵ��һ����д���һ����Ĺ�������ʯ�ؾͲ����ˡ�\n"NOR);
        me->delete_temp("thd/job");
        me->set_temp("thd/dojob",1);
        p_id = me->query("id");
        ob = new(__DIR__"npc/zei");
        ob->set_temp("target",p_id);
        ob->move(__DIR__"mushi");
}