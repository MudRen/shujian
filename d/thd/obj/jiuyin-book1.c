// By Spiderii@ty �츳ϵͳ
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"�����澭�Ͼ�"NOR, ({ "jiuyin zhenjing", "shang juan", "book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","�������𽭺�֮�����澭���Ͼ�������ж����µļ��ܣ�\n"+
                           "���¾�    (daode-jing) \n"
                           "�����湦  (jiuyin-zhengong) \n"
                           "������  (jiuyin-shenfa) \n"
                           "��������  (xuanyin-jian) \n"
                );
                set("treasure", 1);
                set("unique", 1);
                set("value", 0);
                set("material", "skin");
                set("no_drop", 1);
                set("no_give", 1);
                set("no_get", 1);
                set("no_steal", 1);
        }
}

void init()
{
       add_action("do_study", "read");
       add_action("do_unite", "he");
}

int do_unite(string arg)
{
	object me = this_player();
	object ob;
	if( arg ) return 0;
	if((present("shang juan", me)) && (present("xia juan", me))){
		if(me->query_skill("jiuyin-zhengong", 1) < 200
		 || me->query_skill("jiuyin-shenfa", 1) < 150
		 || me->query_skill("xuanyin-jian", 1) < 150 )
			return notify_fail("�㻹�ǽ��˾������ٺϲ������澭�ϡ��¾�ɡ�\n");
		message_vision(HIY"$N�������澭�ϡ��¾�����գ����³�¼�����������澭��\n"NOR,me);
		ob = new(__DIR__"book");
		ob->set("owner",me->query("id"));
		if(!me->query("quest/jiuyin1/owner"))
			log_file("quest/jiuyin",
				sprintf("%s(%s)�������澭�ϡ��¾�����գ���¼�����������澭��\n",
					me->name(1),
					capitalize(getuid(me))
				),me
			);
		me->set("quest/jiuyin1/owner", 1);
		ob->move(me);
		ob =  present("xia juan", me);
		destruct(ob);
		ob =  present("shang juan", me);
		destruct(ob);
		return 1;
      }
      else
		return notify_fail("����Ҫ�ϡ��¾���ܻ�����ա��ο���\n");
}

int do_study(string arg)
{
      int cost, my_skill;
      object me=this_player();
      object where = environment(me);

      if (!arg) return notify_fail("��Ҫ��ʲô��\n");

      if(me->is_busy())
          return notify_fail("��������æ���ء�\n");

      if(where->query("sleep_room")|| where->query("no_fight"))
          return notify_fail("�����㲻�ܶ��顣\n");

      if( me->is_fighting() )
          return notify_fail("���޷���ս����ר�������ж���֪��\n");

      if(! me->query("quest/jiuyin1/pass"))
          return notify_fail("�������͵���ľ����澭���޷��ж���\n");

      if( this_object()->query("owner") != me->query("id"))
          return notify_fail("�������͵���ľ����澭���޷��ж���\n");

      if( !me->query_skill("literate", 1) )
          return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");

      if((int)me->query("potential") < 1 )
          return notify_fail("���Ǳ���Ѿ������ˣ�����ô��Ҳû�á�\n");

      if((int)me->query("combat_exp") < 1000000 )
          return notify_fail("���ʵս���鲻�㣬����ô��Ҳû�á�\n");

      if( me->query_int() < 40 )
          return notify_fail("����Ŀǰ��������������û�а취ѧ������ܡ�\n");

      cost = 40 * ( 1 + ( 35 - (int)me->query("int"))/20 );
      if (cost < 20) cost = 20;
      
      if( me->query("neili") < cost * 2 + 300)
          return notify_fail("��������������޷����������ܡ�\n");

      me->set_temp("last_damage_from", "�ж������书�������Ļ���");
      switch (arg) {
        case "jiuyin-zhengong":
          my_skill = me->query_skill("jiuyin-zhengong", 1);
          if( my_skill >= 200)
              return notify_fail("������⾭������д���Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
          if( my_skill >= me->query_skill("daode-jing",1))
              return notify_fail("����¾�̫ǳ������ѧ��ʲô������\n");
          if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
              return notify_fail("Ҳ����ȱ��ʵս���飬��Ծ���������˵�Ķ��������޷���ᡣ\n");
          else
              write("���ж����йؾ����湦�ļ��ɣ��ƺ���Щ�ĵá�\n");
        //�츳�������ʦ��Ӱ��Ч����  by spiderii@ty ..lsxk�뷨̫����̬��
        if(me->query("relife/quest/lwds")){
         if(random(100) > me->query("relife/quest/lwds")*10)
            write(HIC"�㾭��ת�����޺��������似��䲻�����ڵĵ���˲�������˾����湦�ľ������ڡ�\n"NOR);
            me->set_skill("jiuyin-zhengong",200);
            }
          me->improve_skill("jiuyin-zhengong", ((int)me->query_skill("literate", 1)/5 + 1));
          me->receive_damage("jing", cost );
          me->add("neili", -cost * 2);
          if(me->query_skill("jiuyin-zhengong",1) < 200)
               me->add("potential", - random(2));
          break;             
        case "jiuyin-shenfa":
          my_skill = me->query_skill("jiuyin-shenfa", 1);
          if( my_skill >= 150)
              return notify_fail("������⾭������д���Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
          if( my_skill >= me->query_skill("daode-jing",1))
              return notify_fail("����¾�̫ǳ������ѧ��ʲô������\n");
          if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
              return notify_fail("Ҳ����ȱ��ʵս���飬��Ծ���������˵�Ķ��������޷���ᡣ\n");
          else
              write("���ж����йؾ������ļ��ɣ��ƺ���Щ�ĵá�\n");
        //�츳�������ʦ��Ӱ��Ч����  by spiderii@ty ..lsxk�뷨̫����̬��
        if(me->query("relife/quest/lwds")){
         if(random(100) > me->query("relife/quest/lwds")*10)
            write(HIC"�㾭��ת�����޺��������似��䲻�����ڵĵ���˲�������˾������ľ������ڡ�\n"NOR);
            me->set_skill("jiuyin-shenfa",150);
            }
          me->improve_skill("jiuyin-shenfa", ((int)me->query_skill("literate", 1)/5+1));
          me->receive_damage("jing", cost );
          me->add("neili", -cost * 2);
          if(me->query_skill("jiuyin-shenfa",1) < 150)
               me->add("potential", - random(2));
          break;
        case "xuanyin-jian":
          my_skill = me->query_skill("xuanyin-jian", 1);
          if( my_skill >= 150)
              return notify_fail("������⾭������д���Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
          if( my_skill >= me->query_skill("daode-jing",1))
              return notify_fail("����¾�̫ǳ������ѧ��ʲô������\n");
          if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
              return notify_fail("Ҳ����ȱ��ʵս���飬��Ծ���������˵�Ķ��������޷���ᡣ\n");
          else
              write("���ж����й����������ļ��ɣ��ƺ���Щ�ĵá�\n");
        //�츳�������ʦ��Ӱ��Ч����  by spiderii@ty ..lsxk�뷨̫����̬��
        if(me->query("relife/quest/lwds")){
         if(random(100) > me->query("relife/quest/lwds")*10)
            write(HIC"�㾭��ת�����޺��������似��䲻�����ڵĵ���˲�����������������ľ������ڡ�\n"NOR);
            me->set_skill("xuanyin-jian",150);
            }

          me->improve_skill("xuanyin-jian", ((int)me->query_skill("literate", 1)/5+1));
          me->receive_damage("jing", cost );
          me->add("neili", -cost * 2);
          if(me->query_skill("xuanyin-jian",1) < 150)
               me->add("potential", - random(2));
          break;
         case "daode-jing":
              my_skill = me->query_skill("daode-jing", 1);
          write("���ж��ŵ��¾����ƺ���Щ�ĵá�\n");
          me->improve_skill("daode-jing", ((int)me->query_skill("literate", 1)/5+5) );
          me->receive_damage("jing", cost );
          if(me->query_skill("daode-jing",1)>150)
               me->add("potential", - random(2));
          if(me->query_skill("daode-jing",1)>200)
               me->add("potential", - random(2));
          if(me->query_skill("daode-jing",1)>250)
               me->add("potential", - random(3));
          if(me->query_skill("daode-jing",1)>300)
               me->add("potential", - random(3));
          break;
      }
      return 1;
}

