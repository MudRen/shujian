// /u/dubei/miaojiang


inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�������嶾�̵ĵĽ��أ����������˸��ֲݱ���ľ��Ũ���Ļ�������е�
�����������嶾�̵��ӷ��������￴�ء�
LONG
        );

        set("exits", ([
              "out" : __DIR__"slu9",
               
             ]));
        set("objects", ([
                 __DIR__"npc/jiaozhong" : 2,
             ]));
        set("outdoors", "miaojiang");
        set("ling_count", 2);
        set("jin_count", 2);
        setup();
}
void init()
{
        add_action("do_wa", "wa");
        add_action("do_shao", ({ "shao", "shao" }));
} 
int do_wa(string arg)
{ 
        object lan;
        object me;
        me = this_player();
        if (!( present("xiao tiechan", this_player())))
        return notify_fail("�����ڣ������ж���\n");
        if ( !arg || arg != "hua" )
            return notify_fail("��Ҫ��ʲ�᣿\n");
        if (query("ling_count") > 0) 
       {
        message_vision("$N����������С��������ڳ�һ����֬����\n",me);
        add("ling_count", -1);
        lan=new(__DIR__"obj/lian");
        lan->move(__DIR__"shangu1",);
      me->set_temp("mark/��",1);
        me->add("jingli",-100);
        }
        else
       message_vision("$N���������Ѿ������ڹ��ˡ�\n", me);
        return 1;
}
int do_shao(string arg)
{
     object jinshe,yinshe;
    object me=this_player(), ob;

    if((!arg) || (arg != "lingzhi lan"))
        return notify_fail("��Ҫ����ʲô��\n");
    if( !(ob=present("fire", me)) )
      return notify_fail("��û�е��֮�\n");
    if( !(ob=present("lingzhi lan", me)) )
        return notify_fail("��Ҫ��ʲ�ᣡ\n");
          if (query("jin_count") > 0) 
          {
        message_vision("$N��ȼ��֬����������һ��ɢ��������̴�㡣$N��Ȼ����
�ӹ�ľ�����������ֵ�С�ߡ�\n", me);
         add("jin_count", -1);
         jinshe=new(__DIR__"npc/jinshe");
         jinshe=new(__DIR__"npc/yinshe");
 
         me->add("jingli", -200);
         jinshe->move(__DIR__"shangu1",);
         yinshe->move(__DIR__"shangu1",);
          }
        else
         message_vision("$N���˰��죬ʲ��Ҳû�з��֡�\n", me);
         return 1;
//         destruct(ob);
         return 1;
}
