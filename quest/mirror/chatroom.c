inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
��˵�������ºó�����û�뵽�����ϸ����졣��ô������治��Ϊǧ����ľ��
��������Ҷ��ï����˵�����ʱ���Ƕ���ģ���˱��Ϊ����������ĵط���
������ż������������������ӣ��м��ü�������֦����һ������һ���輸�ˡ�
����̧ͷ���Ͽ���ʱ���ƺ��и�Ӱ������֮���ƶ�������Ҳ���Ƿ紵������ɵ�
�����
LONG);
        set("exits", ([
        "down": __DIR__"guangchang",
        ]));
        setup();
}

void init()
{
    add_action("do_jump","tiao");
}
int do_jump(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg!="down") return notify_fail("��Ҫ��������\n");
      if (me->is_fighting() || me->is_busy() )  return notify_fail("����æ���أ�\n");
        message("vision",
                me->name() + "��ԥ��һ�£�����������������ȥ��\n���ء���һ���죬�ƺ�����"+me->name()+"�Һ���һ��!\n",
                environment(me), ({me}) );
                me->move(__DIR__"guangchang");
        message("vision",
                me->name() + "�Һ�һ���������ϵ���������\n",
                environment(me), ({me}) );
        return 1;
}
//�Ǿ���
int is_mirror() { return 1; }