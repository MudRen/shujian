// Write By Yanyang@SJ 2001.10.3
// Room: /d/changan/beilin.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���߽�����������ı���֮�У����������˾��������ı�����������֮��
�����䣬����Ȫ��ŷ��ѯ������������ı��̡�Ҳ��ʯ����ʯ̨Т�������ؾ�
�������й���������Բ�񡢸����߿̸����ַ���ʯ�̡�ʯ��ȵȡ�
LONG
        );
        set("outdoors", "����");
        set("exits", ([
                "east" : __DIR__"baishulin1",
        ]));

        set("incity",1);
	setup();
}
