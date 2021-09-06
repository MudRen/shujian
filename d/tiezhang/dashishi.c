// Room: /u/bobo/tiezhang/dashishi.c

inherit ROOM;
#include <ansi.h>
#define QUESTDIR "quest/tzautopfm/"


void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
����ʯ���ϻ����ȼ���ţ�ǽ�����ܷ����˴����䣬��һ���������鱦
�ƽ��м�����Ϲ��Ŷ�������������һ����һ�����������ţ��������һƬ
�����ƶ�Ʈ���ڿ��С�ǽ������������Ŀ���һЩͼ�κ�С�֣��ƺ���ʲô
�书��Ҫ��
LONG
	);

	set("exits", ([ 
"out" : __DIR__"taijie-2",
]));
        set("objects", ([
        __DIR__"obj/jia2" : 1,
        ]));
	set("no_clean_up", 0);

	setup();
}


void init()
 {
     object me = this_player();


        add_action("do_study", "yandu");


     if(me->query(QUESTDIR+"combat_exp") && me->query("combat_exp")-me->query(QUESTDIR+"combat_exp")<100000)
       { 
      message_vision( HIW "$N�����������ϵ���������Ȼ������˼��\n"NOR,me);
      message_vision( HIW "$N���˰��죬û����ʲô�������ɵ�ҡ��ҡͷ��\n"NOR,me);

        }
     
else
      { if ( me->query("quest/tzauto/pass",1) 
            && me->query("combat_exp")>= 2000000 
            && me->query_skill("yingou-bifa",1) > 220
            && me->query_skill("lietian-fu",1) > 220
            && me->query_skill("liuye-daofa",1) > 220
            && me->query_skill("tiezhang-zhangfa",1) >220 
            && !me->query("quest/tzauto/over")  
            && random(me->query("kar")) >26 ) 
           
                {  
       message_vision( HIW "$N�����������ϵ���������Ȼ�����մȶ���ʹ�õ��Ʒ���\n"NOR,me);
       message_vision( HIR "$N����˼�������ν��ʽ���޷��Ƿ���֮���ɣ����Կ���������Գ����̣�\n", me);
       message_vision( "              ��������޷����������ܼ�Զ�����Ʋ������֮������\n",me);
       message_vision( "$N���ɵ������˳�˼�С��� \n"NOR, me);
       me->set(QUESTDIR+"time",time());
       me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));
       me->start_busy(3);               
       remove_call_out("thinking");
		 call_out("thinking",5, me );
       
                }
       }            
 }



int thinking(object me)
{
  int i;
  if(!me) return 0;
	
  if(me->query_temp("try_auto")<(3+random(3)))
    { me->add_temp("try_auto",1);
          if(random(2)) tell_object(me,HIG"\n�������ƱȻ�����Ҷ�������츫����ʽ,ֻ����ͷ�Է���...\n"NOR);
             else tell_object(me,HIY"\nͻȻ�䣬���ƺ�ץ����ʲô...\n"NOR);
	  tell_room(environment(me),HIC""+me->query("name")+"�ƺ���˼����ʲô��������ұȻ��š�\n"NOR, ({}));
	  remove_call_out("thinking");
	  call_out("thinking",3+random(3), me);
	}
  else
   {
      me->delete_temp("try_auto");
      i=random(6);
     
     if(i = 5 && random(me->query("kar"))>20)
     {
       tell_object(me,HIG"\n��һ�ƻӳ���ȥ�����飬������ɣ�ȴ��һ����Ҷ������\n"NOR);
       tell_object(me,HIW"\n��һ�ƻӳ�����;��Ȼ��ָ��ʣ�д�˸����ġ��䡰�֣�ȴ��һ�������ʷ���\n"NOR);

       message_vision(HIC"\n$N������������Ц������˵������ԭ����ˣ�ԭ����ˡ���\n"NOR,me); 
       tell_object(me,HIR"��ɹ��İ������似�����������Ʒ��У�\n"NOR);
       me->set("quest/tzauto/over",1);
       log_file("quest/tzautopfm", sprintf("%s(%s) ʧ��%d�γɹ��ں��������似����Դ��%d�����飺%d��",        me->name(1),me->query("id"), me->query(QUESTDIR+"fail"),me->query("kar"),me->query("combat_exp")) );
     }
    else
    {
       tell_object(me,HIG"\n���˼��ã�����Ҫ�졣\n"NOR);
       message_vision(HIC"\n$Nҡ��ҡͷ�������̾�˿�����\n"NOR,me); 
       me->add(QUESTDIR+"fail",1);
       log_file("quest/tzautopfm", sprintf("%s(%s) �ں������似ʧ�ܣ�%d�Ρ���Դ��%d�����飺%d��",        me->name(1),me->query("id"), me->query(QUESTDIR+"fail"),me->query("kar"),me->query("combat_exp")) );
    }
  }

}




int do_study(string arg)
{
	int cost, my_skill;
 	object me=this_player();

	if (!arg) return 0;
	if( me->query("family/family_name") != "���ư�")
		return 0;
	if(me->is_busy())
		return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() )
		return notify_fail("���޷���ս����ר�������ж���֪��\n");

	if( !me->query_skill("literate", 1) )
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");

	if((int)me->query("potential") < 1 )
		return notify_fail("���Ǳ���Ѿ������ˣ�����ô��Ҳû�á�\n");

	if((int)me->query("combat_exp") < 150000 )
		return notify_fail("���ʵս���鲻�㣬����ô��Ҳû�á�\n");

	if( me->query_int() < 30 )
		return notify_fail("����Ŀǰ��������������û�а취ѧ������ܡ�\n");

	cost = 10 * ( 1 + ( 35 - (int)me->query("int"))/20 );

	if (cost < 10) cost = 10;
	if( me->query("jing") < cost * 2 )
		return notify_fail("������̫���ˡ���������Ϣһ�°ɡ�\n");

	switch (arg) {
		case "lietian-fu":
			my_skill = me->query_skill("lietian-fu", 1);
			if( my_skill >= 221)
				return notify_fail("������ⶴ���������Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
			if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
				return notify_fail("Ҳ����ȱ��ʵս���飬��Զ��������������޷���ᡣ\n");
			else
				write("���ж����й����츫�ļ��ɣ��ƺ���Щ�ĵá�\n");
			me->improve_skill("lietian-fu", ((int)me->query_skill("literate", 1)/3 + 1));
			me->receive_damage("jing", cost );
		              me->add("potential", - random(2));
		break;      
                case "axe":
			my_skill = me->query_skill("axe", 1);
			if( my_skill >= 221)
				return notify_fail("����ö��������Ѿ��������У�û��ʲô��ѧ���ˡ�\n");
			if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
				return notify_fail("Ҳ����ȱ��ʵս���飬��Զ��������������޷���ᡣ\n");
			else
				write("���ж����л��������ļ��ɣ��ƺ���Щ�ĵá���\n");
			me->improve_skill("axe", ((int)me->query_skill("literate", 1)/3 + 1));
			me->receive_damage("jing", cost );
			me->add("potential", - random(2));
		break;             
		case "brush":
			my_skill = me->query_skill("brush", 1);
			if( my_skill >= 221)
				return notify_fail("������ⶴ���������Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
			if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
				return notify_fail("Ҳ����ȱ��ʵս���飬��Զ��������������޷���ᡣ\n");
			else
				write("���ж����йػ����ʷ��ļ��ɣ��ƺ���Щ�ĵá�\n");
			me->improve_skill("brush", ((int)me->query_skill("literate", 1)/3+1));
			me->receive_damage("jing", cost );
			me->add("potential", - random(2));
		break;
                case "yingou-bifa":
			my_skill = me->query_skill("yingou-bifa", 1);
			if( my_skill >= 221)
				return notify_fail("������ⶴ���������Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
			if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
				return notify_fail("Ҳ����ȱ��ʵս���飬��Զ��������������޷���ᡣ\n");
			else
				write("���ж����й������ʷ��ļ��ɣ��ƺ���Щ�ĵá�\n");
			me->improve_skill("yingou-bifa", ((int)me->query_skill("literate", 1)/3+1));
			me->receive_damage("jing", cost );
			me->add("potential", - random(2));
		break;
		case "blade":
			my_skill = me->query_skill("blade", 1);
			if( my_skill >= 221)
				return notify_fail("������ⶴ���������Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
			if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
				return notify_fail("Ҳ����ȱ��ʵս���飬��Զ��������������޷���ᡣ\n");
			else
				write("���ж����йػ��������ļ��ɣ��ƺ���Щ�ĵá�\n");
			me->improve_skill("blade", ((int)me->query_skill("literate", 1)/3+1));
			me->receive_damage("jing", cost );
			me->add("potential", - random(2));
		break;

		case "liuye-daofa":
			my_skill = me->query_skill("liuye-daofa", 1);
			if( my_skill >= 221)
				return notify_fail("������ⶴ���������Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
			if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
				return notify_fail("Ҳ����ȱ��ʵս���飬��Զ��������������޷���ᡣ\n");
			else
				write("���ж����й���Ҷ�����ļ��ɣ��ƺ���Щ�ĵá�\n");
			me->improve_skill("liuye-daofa", ((int)me->query_skill("literate", 1)/3+1));
			me->receive_damage("jing", cost );
			me->add("potential", - random(2));
		break;
	}
	return 1;
}


