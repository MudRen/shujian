//qianting.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"���ǰ��"NOR);
        set("long", @LONG
����һ����ȫ�û��������ɵķ��ӣ����Ե�ǽ���ϲ������ͻ�ѣ��Ѵ���
�յ�ͨ�����ž��Ĵ����в�ʱ��������ž��ȼ���������������аڷ���һ��
̫ʦ�Σ����Է�����ʮ�������ӣ������ǽ�Ϲ���һ���ƽ�ĺ���(bian)����
����ȥ������ݵ�ǰԺ�ˡ�
LONG
        );
        
	set("item_desc",([
            "bian" : HIY"				 
            ������������������������������������
            ������������������������������������
            ����������                  ��������
            ��������   ��  ��  ��  ��   ��������
            ����������                  ��������     
            ������������������������������������
            ������������������������������������\n"NOR,
		]));
	 
        set("exits", ([
            "south" : __DIR__"menlang",
            "north" : __DIR__"dayuan",
        ]));         
        
        setup();
}