// box.c ������

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED "������" NOR, ({ "gongde xiang", "xiang", "box" }) );
	set_weight(3000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ��С���ﳣ���Ĺ����䣬ר����������������Ů�ǵľ�\n");
		set("value", 1000);
		set("material", "wood");
		set("no_get",1);
		set("no_drop",1);
		set("amount",30);
	}
	setup();
}

int is_container() { return 1; }

void init()
{
	add_action("do_put", "put");
        add_action("do_ketou", "ketou");
}

int do_ketou(string arg)
{
	object me,what_ob;

	me = this_player();

	if (!arg ||( arg != "gongde xiang" && arg != "xiang" && arg != "box")){
		message_vision( HIY "$N��ͷ��С�������Ƶس������Ұ�һ������Χ��������Ϊ$N�ڷ����裬��һ���ľ��ȣ�\n"NOR,me);
		return 1;
	}
	message_vision( HIY "$N��ͷ��Ը:�����ڴ˳��Ĺ�ݣ���̫���Ͼ������ҽ���ܳͶ���飬�����е�������ΥԸ����������\n"NOR,me);
	what_ob = present("gold_money", me);
	if ((int)me->query("shen",1) < (int)me->query("combat_exp",1)){
		if ( !present("gold", me)){
		message_vision( RED "$N����ͷ�������뻳��Ҫ��ЩǮ������ȴ�����Լ�û������Ǯ���ְ���Ҳ�ò������������Σ�\n"NOR,me);
		return 1;
		}
		else {
			message_vision( HIY"$N����ͷ���ͳ�һ���ƽ�Ͷ�빦���䡣\n"NOR,me);
			what_ob->add_amount(-1);
			if (me->query("shen",1) < 80000){
				me->add("shen",random(500)+200); 
				write(HIW"����������,�����ʱ�ö���.\n"NOR);
			}
		}
	}
	return 1;
}

int do_put(string arg)
{
	object me, obj;
	string item, target; 
	int amount;

	me = this_player();

	if( !arg || sscanf(arg, "%s in %s", item, target)!=2 
	||  sscanf(item, "%d %s", amount, item)!=2
	||  !objectp(obj = present(item, me)) )
		return 0;

	if( obj->query("money_id") == "silver" 
 	 && obj->query_amount() >= 5 && amount >= 5 ){
	    if( me->query("begger") > 0) {
		message_vision( sprintf(HIY "$N��һ%s%s�Ž�%s��\n" NOR,
		obj->query("unit"), obj->name(), this_object()->name()),me );
		obj->set_amount(obj->query_amount() - amount);
		me->add("begger", (-1)*(amount/5));
		if( me->query("begger") < 0) me->set("begger", 0);
		this_object()->add("amount", amount);
		return 1;
 	    }
	}
	return 0;
}
