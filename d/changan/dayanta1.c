// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/dayanta1.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������Ϊһ���߲㷽����������Ϊ��ש���ɣ�����¥��ʽש�������ͼ��
ׯ�����أ�������ΰ������������ţ��������ʯ�̻����������ڽṹ�����
�������ڲ��þ������������徲����֮�С����ܿ����贰��������¥��ֱͨ��
�¡�
LONG
        );
        set("exits", ([
                   "up"  : __DIR__"dayanta2",
                 "west"  : __DIR__"ciensi",
        ]));

        set("incity",1);
	setup();
}