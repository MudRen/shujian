#include <ansi.h>
inherit ROOM;
#define QUESTDIR2 "quest/ѩɽ�ɺ�/����ƪ/"

void create()
{
        set("short","ɽ·");
        set("long", @LONG
һ����������̤����С�������������������������ɽ����չ�����Ե���
��(grass) �ߴ���ߣ���ס����⡣ɽ���е�һ�ж��Ե���ɭ�İ�������ʹ��
�ֲ���ǰ���ĵ�·��
LONG                           
        );

        set("exits", ([
                "southeast" : __DIR__"slu1",
        ]));
        set("item_desc", ([
                "grass": "�����Ӳ�(grass)���ܣ������ƺ����Բ���(push)���ǡ�\n",
                "�Ӳ�": "������Ӳ�(grass)���ܣ������ƺ����Բ���(push)���ǡ�\n"
        ]));
        setup();
}
void init()
{
        add_action("do_push", "push");
}
int do_push(string arg)
{
	  object me=this_player();
        if( arg == "grass" || arg == "é��" || arg == "��")
        {
        message_vision("$N����·�ߵ��Ӳݣ�������һ����������·��\n", this_player());
        if(me->query(QUESTDIR2+"start")&& me->query_temp(QUESTDIR2+"zhenxiang") && !random(3))
        {
           set("exits/northwest", __DIR__"houshan_copy");
           remove_call_out("close_path");
           call_out("close_path", 5);
        }
        else if( !query("exits/northwest") ) 
        {
        set("exits/northwest", __DIR__"houshan");
        remove_call_out("close_path");
        call_out("close_path", 5);
        }
        return 1;
        }
}
void close_path()
{
        if( !query("exits/northwest") ) return;
        message("vision",
"һ��紵�����Ӳݻ��˻Σ�����û����������·��\n",
                this_object() );
                delete("exits/northwest");
}
