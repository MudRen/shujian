// Write By Yanyang@SJ 2001.10.1
// Room: /d/changan/ljyanting.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����м���һ�Ŵ����ӣ��������������ʮ���ˡ����ӵ�һ��ͨ��������
��Ա��Ϊ�˺�ˬ���⽻���º��ܣ����˶�ʱ���������ﶼ�����£��ɴ���ǰԺ
�յ���¶�����硣
LONG
        );
        set("exits", ([
                "south"  : __DIR__"ljzhengting",
        ]));

        set("incity",1);
	setup();
}

       
