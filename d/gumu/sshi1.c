#include <ansi.h>
inherit ROOM;

void create()
{ 
       set("short",HIC"ʯ��"NOR);
       set("long", @LONG
����Ҳ������֮������̧ͷ�����������Ҷ����������д�����ּ����ţ�
�㿴��һ�ᣬ���������ѽ⡣�Ҷ����Ͻǻ���һ��ͼ�������书�޹أ�����ϸ
���������Ƿ���ͼ��ʯ�����·������������(down)�ߡ�
LONG
     );
        set("item_desc", ([
             "down": HIB"�ں����ģ��������С�\n"NOR,
        ]));
        set("exits", ([
              "up" : __DIR__"shiguan",                 
        ]));
        setup();
}

void init()
{
	object me = this_player();
	
	if(me)
	{
		if(!me->query("quest/jiuyin1/pass")
		&& !me->query("quest/jiuyingm/pass") )
		{
			me->delete_skill("jiuyin-shenfa");
			me->delete_skill("jiuyin-zhengong");
			me->delete_skill("jiuyin-shenzhua");
//                        me->delete_skill("yinlong-bian");
		}
	}
	
        add_action("do_look", "look"); 
        add_action("do_look", "kan");
        add_action("do_walk", "walk");
        add_action("do_walk", "leave");
        add_action("do_study", "yandu");
}

int do_look(string arg)
{
	object me=this_player();
	int i, time;
	if ( arg =="map") {
		write(HIY"���������Ƿ�ͼ�����в��ɴ�ϲ��ԭ���ǻ�����ǳ�Ĺ���ص���\n"NOR);
		me->set_temp("map", 1);
		me->start_busy(1);
		return 1;         
	}
	if ( arg =="ceiling") {
		write(HIY"�㿴���Ҷ��������Ķ������������С�֡�\n"NOR);
		me->set_temp("ceiling", 1);
		me->start_busy(1);
		return 1;
	}
	if ( arg =="zi") {
		write(HIY"��������ЩС�֣��ƺ�����һЩ�书Ҫ����\n"NOR);
		if( !me->query_temp("ceiling")
                 || me->query("combat_exp", 1) < 2000000 ){
			tell_object(me,HIY"��������д�ļ����Ѷ����㿴��һ�ᣬ�����Լ�����������㣬ֻ�÷����ˡ�\n"NOR);
			return 1;
		}
                i = (me->query("combat_exp") - 1000000) / 500000;
		time = time() - me->query("quest/jiuyingm/time");
                if ( me->query("quest/jiuyingm/fail") >= i && me->query("registered") < 3 ){
			tell_object(me,HIY"��������д�ļ����Ѷ����㿴��һ�ᣬ�����Լ��ϴο����Ժ����ӵ��������������������塣\n"NOR);
			return 1;
		}
                if ( time < 86400 ){
			tell_object(me,HIY"��������д�ļ����Ѷ������Դ��ϴο�����˼��һֱ�޷�ƽ��������������Ҫ�ٹ�һ��ʱ�䡣\n"NOR);
			return 1;
		}

                 if(( random(me->query("kar")) > 28
                 && me->query("kar") <31
                 && me->query("buyvip")
                 && me->query("combat_exp")>=2000000
                 && random(10) == 3 
                 && me->query("int") > 30)
         || me->query("quest/jiuyingm/pass") ){

			write(HIR"�㶸ȻһƳ�䣬��������С�֡������澭�ڹ�Ҫ���������˷ܼ��ˡ�\n"NOR);
			write(HIC"���о���һ�£�����Ӧ�����ж�(yandu)Щ���¾�(daode-jing) \n"NOR);
			write(HIB"�����湦(jiuyin-zhengong)�Լ�������(jiuyin-shenfa)��\n"NOR);
                        write(HIM"������צ(jiuyin-shenzhua)�Լ�����������(yinlong-bian)��Ƥë��\n"NOR);
			if( !me->query("quest/jiuyingm/pass"))
				log_file("quest/jiuyin",
					sprintf("%-18sʧ��%s�κ��ڹ�Ĺʯ���ϵõ������澭������%d����%d��\n",
						me->name(1)+"("+capitalize(getuid(me))+")",
						chinese_number(me->query("quest/jiuyingm/fail")),
						me->query("kar"), 
						me->query("int") 
					), me
				);
			me->set("quest/jiuyingm/pass", 1);
		}
		
         if(( random(me->query("kar")) >= 28
                 && random(15) == 10 
                 && me->query("int") > 40)
                 && me->query_temp("quest/gmsuper/ask")
         || me->query("quest/gmsuper/pass") ){

                        write(HBMAG"\n�㿴�������������С���Աߣ��������һЩͼ����ʽ���ƺ����Ĺ��ѧ�йء�\n"NOR);
			write(HIW"����ϸ�о���һ�£�����ʯ�������̻��ģ����������С��Ů�ı�����ѧ��Ҫ�� \n"NOR);
			write(HIW"������������ļ�¼�˹�Ĺ��ѧ�����������һ����������澭����󡹦����Ȼ�����ƺ�����仯�� \n"NOR);
	   if( !me->query("quest/gmsuper/pass"))
				log_file("quest/gmsuper",
					sprintf("%-18sʧ��%s�κ��ڹ�Ĺʯ���ϵõ���Ĺ��ѧ�ܸ٣�����%d����%d��\n",
						me->name(1)+"("+capitalize(getuid(me))+")",
						chinese_number(me->query("quest/jiuyingm/fail")),
						me->query("kar"), 
						me->query("int") 
					), me
				);
   me->set("quest/jiuyingm/pass", 1);
                        me->set("quest/gmsuper/pass", 1);
		}
		
		else {
			me->add("quest/jiuyingm/fail", 1);
			me->set("quest/jiuyingm/time", time());
			log_file("quest/jiuyin",
				sprintf("%-18s���%s�Σ�û�з��ֹ�Ĺʯ���ϵľ����澭��\n",
                      			me->name(1)+"("+capitalize(getuid(me))+")", 
                      			chinese_number(me->query("quest/jiuyingm/fail"))
                      		), me
                      	);
			write(HIY"��������д�ļ����Ѷ����㿴��һ��ͷ����ˡ�\n"NOR);
		}
		me->delete_temp("ceiling");
		return 1;         
	}
	return notify_fail("��Ҫ��ʲô��\n");
}

int do_walk(string arg)
{ 
        object me=this_player();
        if (me->is_busy() || me->is_fighting())
              return notify_fail("����æ���ģ�\n");
        if ( arg =="down"){ 
             if(!me->query_temp("map") || me->query_skill("force")<115 )
                   return notify_fail("������������ߣ�������ԥ������������˽š�\n");      
           tell_object(me,HIM"\n�㶫ת���䣬Խ��Խ�͡�ͬʱ���½�����ʪ��������Լ��ȥ���������ǲ����\n"+
                             "����һ�ᣬ��·�涸�����Ǳ�ֱ���¡��½���ԼĪ���ʱ������·��ƽ��ֻ��\n"+
                             "ʪ��ȴҲ���أ�������������������ˮ����·��ˮû���ס�Խ��ˮԽ�ߣ�����\n"+
                             "�������������롣\n"NOR);
           me->delete_temp("map");
           me->move(__DIR__"gmanhe1");
           tell_room(environment(me), me->name() + "��"HIC"ʯ��"NOR"�첽���˹�����\n", ({ me }));
           return 1;
        }
        return notify_fail("����ʯ����������ȥ����֪����Ǻã�\n");
}

int do_study(string arg)
{
	int cost, my_skill;
 	object me=this_player();

	if (!arg) return 0;

	if( ! me->query("quest/jiuyingm/pass"))
		return 0;

	if(me->is_busy())
		return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() )
		return notify_fail("���޷���ս����ר�������ж���֪��\n");

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
			if( my_skill >= 201)
				return notify_fail("������ⶴ���������Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
			if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
				return notify_fail("Ҳ����ȱ��ʵս���飬��Զ��������������޷���ᡣ\n");
			else
				write("���ж����йؾ����湦�ļ��ɣ��ƺ���Щ�ĵá�\n");
			me->improve_skill("jiuyin-zhengong", ((int)me->query_skill("literate", 1)/5 + 1));
			me->receive_damage("jing", cost );
			me->add("neili", -cost * 2);
			me->add("potential", - random(2));
		break;      
                case "daode-jing":
			my_skill = me->query_skill("daode-jing", 1);
			if( my_skill >= 220)
				return notify_fail("����ö��������Ѿ��������У�û��ʲô��ѧ���ˡ�\n");
			if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
				return notify_fail("Ҳ����ȱ��ʵս���飬��Զ��������������޷���ᡣ\n");
			else
				write("���ж��ŵ��¾�������������Ϊ���г�����\n");
			me->improve_skill("daode-jing", ((int)me->query_skill("literate", 1)/5 + 1));
			me->receive_damage("jing", cost );
			me->add("neili", -cost * 2);
			me->add("potential", - random(2));
		break;             
		case "jiuyin-shenfa":
			my_skill = me->query_skill("jiuyin-shenfa", 1);
			if( my_skill >= 201)
				return notify_fail("������ⶴ���������Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
			if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
				return notify_fail("Ҳ����ȱ��ʵս���飬��Զ��������������޷���ᡣ\n");
			else
				write("���ж����йؾ������ļ��ɣ��ƺ���Щ�ĵá�\n");
			me->improve_skill("jiuyin-shenfa", ((int)me->query_skill("literate", 1)/5+1));
			me->receive_damage("jing", cost );
			me->add("neili", -cost * 2);
			me->add("potential", - random(2));
		break;
                case "yinlong-bian":
			my_skill = me->query_skill("yinlong-bian", 1);
			if( my_skill >= 201)
				return notify_fail("������ⶴ���������Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
			if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
				return notify_fail("Ҳ����ȱ��ʵս���飬��Զ��������������޷���ᡣ\n");
			else
				write("���ж����йؾ��������޵ļ��ɣ��ƺ���Щ�ĵá�\n");
			me->improve_skill("yinlong-bian", ((int)me->query_skill("literate", 1)/5+1));
			me->receive_damage("jing", cost );
			me->add("neili", -cost * 2);
			me->add("potential", - random(2));
		break;
		case "jiuyin-shenzhua":
			my_skill = me->query_skill("jiuyin-shenzhua", 1);
			if( my_skill >= 201)
				return notify_fail("������ⶴ���������Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
			if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
				return notify_fail("Ҳ����ȱ��ʵս���飬��Զ��������������޷���ᡣ\n");
			else
				write("���ж����йؾ�����צ�ļ��ɣ��ƺ���Щ�ĵá�\n");
			me->improve_skill("jiuyin-shenzhua", ((int)me->query_skill("literate", 1)/5+1));
			me->receive_damage("jing", cost );
			me->add("neili", -cost * 2);
			me->add("potential", - random(2));
		break;
	}
	return 1;
}
