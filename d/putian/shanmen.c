// Room: /d/putian/shanmen.c
// Lklv 2001.9.11

#include <ansi.h>
inherit ROOM;
string look_gate();
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�ϵ�ʯ�ף���ǰ�������ȸߴ�ĺ��ź͸߸ߵ�Ժǽ��ǽ���ɰش��̣���ǰ�м�
�������಼ɮ�µ�ɮ���ڵ���ͷɨ�ء���ϸ����������Ŀ��࣬���׳��ԭ����
��������������ֱ�Ժ�������˳�Ϊ�����ֵĸ������������¡�ɽ���Ϸ�������һ
���̽�ľ��(bian)��
LONG
        );

        set("exits", ([
                "northdown" : __DIR__"road08",
                "east" : __DIR__"xl3",
                "west" : __DIR__"xl2",

        ]));
        set("item_desc", ([
        	"gate" : (: look_gate :),
		"bian" :  HIY"
             ����������������������������������������
             ����������                      ��������
             ��������     ��  ��  ��  ��     ��������
             ��������                        ��������
             ����������������������������������������\n"NOR,
        ]));

        set("objects",([
        	__DIR__"npc/seng-bing" : 2,
        ]));

        set("outdoors", "����");
        setup();
}

void init()
{
        add_action("do_knock", "knock");
}

int close_gate()
{
        object room;

        if(!(room = find_object(__DIR__"qianyuan")))
                room = load_object(__DIR__"qianyuan");
        if(objectp(room)){
                delete("exits/south");
                message("vision", "ƹ��һ�����������˰Ѵ��Ź����ˡ�\n",this_object());
                room->delete("exits/north");
                message("vision", "׳��ɮ����ǰ�Ѵ��Ź���������\n", room);
        }
        else message("vision", "ERROR: gate not found(close).\n", room);
}

int do_knock(string arg)
{
        object room;

        if (query("exits/south"))
                return notify_fail("�����Ѿ��ǿ����ˡ�\n");

        if (!arg || (arg != "gate" && arg != "south"))
                return notify_fail("��Ҫ��ʲô��\n");

        if(!( room = find_object(__DIR__"qianyuan")) )
                room = load_object(__DIR__"qianyuan");
        if(objectp(room)){
                set("exits/south", __DIR__"qianyuan");
                message_vision("$N�����Ż�����������ߵ��ߵ��֨��һ����һλɮ�˴򿪴�����������Ŀ�����´�����$N��\n",this_player());
                room->set("exits/north", __FILE__);
                message("vision", "���洫��һ����������׳��ɮ��Ӧ����ǰ�Ѵ��ſ���\n", room);
                remove_call_out("close_gate");
                call_out("close_gate", 10);
        }
        return 1;
}

int valid_leave(object me, string dir)
{
        if ( dir != "south" )
                return ::valid_leave(me, dir);

        if (me->query("gender") == "Ů��" && !me->query("luohan_winner")){
                return notify_fail("׳��ɮ��˵������λŮʩ��������ذգ����´Ӳ��Ӵ�Ů�͡�\n");
        }

        if (me->query("family/family_name") == "������"){
                message_vision("׳��ɮ�˲����ÿ���˵����ʦ�������ˣ������\n", me);
                return ::valid_leave(me, dir);
        }
        if (present("yingxiong ling", me)){
                message_vision("׳��ɮ�˺�ʮΪ�񣬲����ÿ���˵����ԭ���ǹ�ͼݵ�����������\n", me);
                return ::valid_leave(me, dir);
        }
        if (me->query("shen") <= -100000 && !me->query("luohan_winner")){
                return notify_fail("׳��ɮ����ʱ������ֿ��һ��ѩ���Ľ䵶���������λε�\n"
                        "�����׼����ؿڣ���üŭĿ��˵�������аħ������������ҹ�����\n"
                        "�Ժ��ٸ��߽�����һ��������ʱ��ն�����ǵĹ��ȣ�\n");
        }
        return ::valid_leave(me, dir);
}

string look_gate()
{
        return "һ���������ߵ����ɼľ��ͭ���š�\n";
}
