// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/qianzhuang.c

inherit ROOM;

void create()
{
        set("short", "����Ǯׯ");
        set("long", @LONG
���ǳ����ǵ�һ�����ֺ�Ǯׯ���ϰ���ɽ���ˣ����Ǯׯ��������������
����ʱ�Ϳ�ʼ����һֱ�����������Ǯׯ�������ǳ��ã�������ȫ������
�����˷ֵꡣ�����е���Ʊͨ��ȫ�������ڰ���ʮ�ּ򵥣�һ���߸ߵĹ�̨��
��װ����դ����
LONG
        );

        set("exits", ([
                "east" : __DIR__"southjie1",
        ]));

        set("objects", ([
                __DIR__"npc/qianyankai" : 1,
        ]));

        set("incity",1);
        setup();
}
