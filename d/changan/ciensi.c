// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/ciensi.c

inherit ROOM;

void create()
{
        set("short", "�ȶ���");
        set("long", @LONG
�������ȶ��£��ߴ������ͦ���������Ի�����������ʯʨ�ӡ���˵����
�ĺ��һ��ǳ��Ի��ϵ����ʡ���Ժ�ڵĴ������߸��������߲�ͻأ����գ���
��׳�ۡ����ڹŰ�ɭɭ��������Ƭ�������ӹ�¥ңң��ԡ�Ժ��������ʯ��Ⱥ��
ΪһЩ������ʿ����̡�
LONG
        );
        set("outdoors", "����");
        set("exits", ([
                  "east"  : __DIR__"dayanta1",
             "northwest"  : __DIR__"changjie2",
        ]));

        set("incity",1);
	setup();
}

