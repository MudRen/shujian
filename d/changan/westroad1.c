// Write By Yanyang@SJ 2001.10.13
// Room: /d/changan/westroad1.c

inherit ROOM;

void create()
{
        set("short", "�ٵ�");
        set("long", @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ���������������������
�����̣����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����
������������߷ɳ۶���������һ·��������·��������������������֡�
�����ѿ����������������ǵ��������ˡ�
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"  : __DIR__"westmen",
                "west"  : __DIR__"westroad2",
                        ]));
                        
        setup();
}
