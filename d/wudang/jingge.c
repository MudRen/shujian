// cangjingge.c �ؾ���
// by ahunter and shang  97/6
inherit ROOM;

string* books = ({
        __DIR__"obj/laozi1",
        __DIR__"obj/ddj1",
        __DIR__"obj/laozi2",
        __DIR__"obj/ddj1",
        __DIR__"obj/laozi8",
        __DIR__"obj/laozi13",
        __DIR__"obj/laozi1",
        __DIR__"obj/laozi16",
        __DIR__"obj/laozi18"
});

void create()
{
        set("short", "�ؾ���");
        set("long", @LONG
�����ǲؾ��󣬿�ǽ��һ����ܣ������˵��̵ĵ伮��������һ��������
�Ĵ����ӣ�����Ҳ�������顣һ����ͯ���������鼮��
LONG
        );

        set("exits", ([
                "east" : __DIR__"donglang1",
        ]));

        set("objects", ([
                __DIR__"npc/daotong" : 1,
                books[random(sizeof(books))] : 1,
                books[random(sizeof(books))] : 1
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        object *ob = deep_inventory(me);
        int i = sizeof(ob);
        if((dir == "east")){
        while (i--)
        if(ob[i]->id("daode jing"))
           return notify_fail("���¾�����Я����� !\n");               
        }
        return ::valid_leave(me, dir);
}
