inherit ROOM;

void create()
{
        set("short", "�Ҷ�");
        set("long", @LONG
����һ��ɽ���ϵ�С�Ҷ�����Ȼ����������Ҳ���㹻�Ļ�ռ䡣
LONG
        );
        set("exits",([
                "out" : __DIR__"cave.c",
        ]) );
        set("no_clean_up",0);
        setup();
}

