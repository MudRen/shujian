inherit ROOM;
void create()
{
        set("short", "Сɽ");
        set("long", @LONG
һ����ɽͷ����ͷ�����ǰ��Ȼ���ʣ�����ɽ������һ��Ƭ���һ��ԣ���
�ڻ�������Լ¶���˼���ͥԺ�ķ��ܣ��ƺ�����һƬ���ŵĽ������Ǳߡ���
����һ����ȥ��������ɽʱ��ŵ���ʯ�Ѿ����ŵ��ˣ�����Ҳ�ز��������ˡ�
�������߸���һ��Сɽ�壬
LONG
        );
        set("exits", ([ 
                "northdown" : __DIR__"taohua1",
                "eastup" : __DIR__"hill1",
        ]) );
        set("no_clean_up", 0);
        set("outdoors","�һ���");

        setup();
}

int valid_leave(object me, string dir)
{
        object *ob;
        int i;
        if (dir == "northdown" || dir == "eastup") {
           ob = all_inventory(me);
           for(i = 0; i < sizeof(ob); i++) {
               if (userp(ob[i])) {
                  message_vision("$N��$n���ڵ��ϣ��߽����С�\n",me,ob[i]);
                  ob[i]->move(this_object());
               }
           }
        }
        return ::valid_leave(me, dir);
}

