// Room: /u/jpei/guiyun/shufang.c
// Modify By River@SJ 99.09
inherit ROOM;

void create()
{
        set("short", "�鷿");
        set("long", @LONG
������ׯ��ƽ�ն���ĵط�������������Ŀ��ȫ��ʫ�ĵ伮���������ϰ�
�����ͭ���������������ǹ�����Ϲ���һ��ˮī��(hua)�� ��������һ��
��齣�һλ��ĸߴ����������������ϡ�
LONG
        );

        set("exits", ([
                "west" : __DIR__"houting",
        ]));

        set("item_desc",([
                "hua" : "
�����滭����һ����������������֮ҹ��ͥ�������ְ����������쳤���������į��
�������½�����һ�״ʣ�\n
\t\t��ҹ���˲�ס����
\t\t����ǧ���Σ���������
\t\t���������ƽ��С�
\t\t�����ģ�������������
\t\t����Ϊ������
\t\t��ɽ�����ϣ����̡�
\t\t�������¸����ݣ�֪���٣��Ҷ���˭����\n
\t\t\t\t\t�¿����š�������˲���Ϳѻ�����֡�\n
"
        ]) );

        set("objects", ([
                __DIR__"npc/lucf": 1,
		MEDICINE_D("jiuhuawan") : 1,
		"/d/music/obj/flute-book" : 1,
        ]));

        setup();
}

void init()
{
        add_action("do_look","look");
        add_action("do_zhai",({"zhai", "qu"}));
}

int do_look(string arg)
{
        object me;
        me = this_player();
        if(me->query_temp("thd/bagua") || present("tie bagua",me)){
        set("long", @LONG
������ׯ��ƽ�ն���ĵط�������������Ŀ��ȫ��ʫ�ĵ伮���������ϰ�
�����ͭ���������������ǹ�����Ϲ���һ��ˮī��(hua)�� ��������һ��
��齣�һλ��ĸߴ����������������ϡ�
LONG
);
        me->look(arg);
        }
        else {
        if (!arg) {
        set("long", @LONG
������ׯ��ƽ�ն���ĵط�������������Ŀ��ȫ��ʫ�ĵ伮���������ϰ�
�����ͭ���������������ǹ�����Ϲ���һ��ˮī��(hua)�� ��������һ��
��齣�һλ��ĸߴ����������������ϡ�����һ̧ͷ�������鷿���֮�϶�
�Ű�Ƭ��Ƭ������������״��ȴ�ֲ���Ѱ���İ���(bagua)��ô�ŵ����룬��
�����䣬��б���ơ�
LONG
        );
        me->look(arg);
        }
        else if(arg == "bagua") {
          write("��Ƭ��Ƭ������������״��ȴ�ֲ���Ѱ���İ�����ô�ŵ����룬�������䣬��б���ơ�\n");
          me->set_temp("thd/bagua_look", 1);
          return 1;
          }
       }                
}

int do_zhai(string arg)
{
       object me, ob,*clone ;
       int i,j;
       mapping fam;
       me = this_player();
       fam = me->query("family");
       if( !me->query_temp("thd/bagua_look")) return 0;
       if (!arg || (arg != "bagua"))
              return notify_fail("��Ҫժʲô����\n");
       if (me->is_busy() || me->is_fighting())
              return notify_fail("����æ���ģ�\n");
       if(!fam || fam["family_name"] != "�һ���")
              return notify_fail("�㲻���һ����ĵ��ӣ���ô��˽�����һ����������\n");
        if ((me->query_skill("qimen-bagua",1)<122)&&(me->query_skill("bihao-chaosheng",1)<131))
              return notify_fail("��ժ�°��Կ��˿���ʵ��ûʲô�ر�֮�����ַ��˻�ȥ��\n");
       if( me->query_temp("thd/bagua"))
              return notify_fail("�㲻���Ѿ��ù�������ô����ô��ô̰�ģ�\n");
       if(present("tie bagua", me))
              return notify_fail("�����ϲ����Ѿ�����������ô����ô��Ҫ�ã�\n");
       ob = unew(__DIR__"obj/bagua");
       if(!clonep(ob)) return notify_fail("�㷢�������Զ��������ȡ��������\n");
       i = ob->query("unique");
       clone = filter_array(children(base_name(ob)), (: clonep :));
          j = sizeof(clone);
          while (j--) if (!clone[j]->query("clone_by_wizard")) i--; 
       if(clonep(ob) && i < 0){
           destruct(ob);
           return notify_fail("�㷢�������Զ��������ȡ��������\n");
       }
       message_vision("$N���ֵ������ժ��һֻ�����ԡ�\n",me);
       ob->move(me);
       me->set_temp("thd/bagua",1);
       me->delete_temp("thd/bagua_look");
       return 1;
}

