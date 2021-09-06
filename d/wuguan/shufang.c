//shufang.c
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "/d/suzhou/npc/lchj.h";//���Ǿ�
void create()
{
        set("short", "�鷿");
        set("long", @LONG
�������Ϲ������鷿���������Ѿ��ܾ�û�������ˡ���������Ӳ�ԫ����
�����˳��ָ��һЩϲ�������С���ǡ��鷿��Χ���������������ضѷ�
�źܶ��鼮�����Դ��ŵ��Ǳ�ǽ��д�˼�����Ŀ�Ĵ��֣�dazi����
LONG
        );
        set("item_desc", ([
		"dazi" : "
    ��������������������������������������
    ��������������������������������������
    ����������                    ��������
    �������� �� ����׳��Ŭ����������������
    ����������                    ��������
    ����������������������������  ��������
    ����������                    ��������
    �������� �� ���ϴ�ͽ���ˡ�  ����������
    ����������                    ��������
    ��������������������������������������
    ��������������������������������������\n" ,
 
	]));

        set("exits", ([
                "south" : __DIR__"zoulang6",
        ]));

        set("objects", ([
                __DIR__"npc/dizi5" : 1,
        ]) );
        
        setup();

}
void init()
{
	add_action("do_search", ({"search","xunzhao"}));
}
int do_search(string arg)
{
	object me = this_player();
	object book;
	if(!me->query_temp(QUESTDIR2+"askxieyang" ))
		return 0;	
	if( arg == "book" || arg == "tangshi xuanji" || arg=="��ʫѡ��")
  {       
		message_vision(HIY"\n$N����ܿ�ʼѰ����ʫѡ��.....\n"NOR, me);
                book=new("/d/wuguan/obj/tangshixuanji");
 
			message_vision(HIC"$N���ֲ�������ϵ�һ�����顣\n$N������ʫѡ����Ȼ�����Ի������С�\n"NOR, me);
			book->set("owner",me->query("id"));
			book->move(me);
			me->delete_temp("quest/busy");//
			me->delete_temp(QUESTDIR);
			me->start_busy(1);
			me->set(QUESTDIR2+"over",1);
			me->set(QUESTDIR+"time",time());
			me->set(QUESTDIR+"combat_exp",me->query("combat_exp")); 
			message_vision(HIC"$N��æ��ʰ���鼮��͵͵�뿪��ݡ�\n"NOR, me);
			me->move("/d/xiangyang/damen");
		return 1;
	}
	return 0;
}
int valid_leave(object me, string dir)
{
        me->set_temp("mark/literate", 0);
        return 1;
}
