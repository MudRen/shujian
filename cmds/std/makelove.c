// makelove.c
// modified by wind
// modified by akuma 10:36 AM 4/13/2002

#include <ansi.h>
void ing(object, object);
void post(object me, object obj);
void sec_post(object me, object obj);
void trd_post(object me, object obj);
void over(object, object);

int main(object me, string arg)
{
	object obj, *ob,where;
	int i;

	if ( !arg || !objectp(obj = present(arg, environment(me)))) return notify_fail("�����˭������\n");

	if ( !obj->is_character() || me->query("gender") == obj->query("gender") )
		return notify_fail("���������������²��аɣ�\n");

	if ( !living(obj)) return notify_fail("�˼Ҷ������ˣ��㻹...\n");

	if ( !environment(me)->query("sleep_room") || environment(me)->query("no_sleep_room"))
		return notify_fail("�ܵ��Ҹ���ܰ����ĵط��ɡ�\n");

	if ( me->query("gender") == "Ů��" && me->query_condition("pregnant") )
		return notify_fail ("���Ѿ������ˣ���Ҫ��������Ҫ���ˣ�\n");

	if ( obj->query("gender") == "Ů��" && obj->query_condition("pregnant") )
		return notify_fail ("�˼��Ѿ������ˣ���Ҫ��������ɹ����̵�\n");

	if ( me->query("gender") == "Ů��" && me->query_condition("yuejing_butiao") ) {
		me->force_me("say �˼������Ǹ�����Ҫ����");
		return 0;
	}
	if ( obj->query("gender") == "Ů��" && obj->query_condition("yuejing_butiao") ) {
		obj->force_me("say �˼������Ǹ�����Ҫ����");
		return 0;
	}
	if ( (int)me->query("age", 1) < 18 ) return notify_fail ("Ҫ֪����ͯ�ӹ���������Ҫ��ϧ��\n");

	if ( (int)obj->query("age", 1) < 18 ) return notify_fail ("�۸���ôС�ĺ��ӣ�������ѽ��\n");
	
	where=environment(me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
		if( ob[i]->is_character()&&ob[i] != me && ob[i]!=obj&&!wizardp(ob[i]) )
			return notify_fail("������б����أ��಻����˼ѽ��\n");

	if(!me->query_temp("makelove/quest")) {
		if( me->query("gender") == "����" ) {
			message_vision(HIM "$N��������$n���˫�ֻ�����$n�����䣬\n\n" +
				"��$n��������˵�����װ��ģ�������\n\n"NOR, me, obj);
			tell_object(obj, HIR "ɵ��Ҳ�ܿ�����������㹲��������\n" +
				"�����Ը�⣬����Ҳ��" + me->name() + "("+(string)me->query("id")+")" +
				"��һ�� makelove ָ�\n" NOR);
		CHANNEL_D->do_channel( me, "sys", sprintf("%s(%s)"HIR"��%s"HIR"���%s(%s)�Ǹ�����������Ħѧϰ��\n",
			me->name(1),getuid(me),(string)where->query("short"),obj->name(1), geteuid(obj)			
			));
		}
		else {
			message_vision(HIM "��֪����Ϊ��⣬���Ǿƾ����������Ϊ�˷ܣ�$N��С�������ģ�\n\n" +
				"���žƱ���$Nֱ�����ض���$n���װ��ġ�����˵�����Ⱦơ������ԡ���\n\n"NOR, me, obj);
			tell_object(obj, HIR "ɵ��Ҳ�ܿ�����������㹲��������" +
				"�����Ը�⣬����Ҳ��" + me->name() + "("+(string)me->query("id")+")" +
				"��һ�� makelove ָ�\n\n" NOR);
		CHANNEL_D->do_channel( me, "sys", sprintf("%s(%s)"HIR"��%s"HIR"���%s(%s)�Ǹ�����������Ħѧϰ��\n",
			me->name(1),getuid(me),(string)where->query("short"),obj->name(1), geteuid(obj)			
			));
		}
		obj->set_temp("makelove/quest",1);
	}
	else {
		if( me->query("gender")=="����" ) {
			message_vision(HIM "$N�ؾ��ƵĶ���$n���۾�������һ�Բ�����ͻȻһ�ѱ�ס$n��һ˫�ȴ���ס��$n���죬\n" +
				"��$n��ֱ�������������Ʊ����������һ�ء���\n\n"NOR, me, obj);
			call_out("ing", 1, me, obj);
		}
		else {
			message_vision(HIM "$n�����ܿ���$N�ߺ�Ķ�����$N��������$n�Ļ�����\n" +
				"ĬĬ�ط�����ԡ��$nȴ��Ҳ�̲�ס��һ�ѽ�$N������������\n\n"NOR, me, obj);
			call_out("ing", 1, obj, me);
		}
		me->delete_temp("makelove/quest");
	}
	log_file("static/makelove",sprintf("%s(%s)��%s(%s)��%s������%s\n",
		me->name(1),getuid(me),obj->name(1), geteuid(obj),(string)where->query("short"),ctime(time()) ));
	return 1;
}

void ing(object me, object obj)
{
	if( obj->query("id") != me->query("marry/id") ) {
		if ( me->query("gender")=="����" ) {
			message_vision(HIW"$N����ظ�����$n��ȫ��������$n�����ա��˷ܵ�˵�����һ��治��Ұ���㣡\n\n"NOR,
				me, obj);
			obj->force_me("blush");
		}
		if ( me->query("gender")=="Ů��" ) {
			if ( me->query("marry") ) {
				message_vision(HIW"$N������˿����ɫ������㡭���������Ϲ���������\n\n"NOR,
					me, obj);
				obj->force_me("hehe");
			}
			else {
				message_vision(HIW"$N������˿����ɫ������簮�������ˡ���\n\n"NOR,
					me, obj);
				obj->force_me("ok");
			}
		}
	}
	else {
		if ( me->query("gender")=="����" ) {
			message_vision(HIW"$N����ظ�����$n��ȫ��������$n�����ա�˵����������ˣ��������󣿣�\n\n"NOR,
				me, obj);
			obj->force_me("iddle");
		}
		if ( me->query("gender")=="Ů��" ) {
			message_vision(HIW"$N������˿����ɫ������㡭���������Ϲ���������\n\n"NOR,
				me, obj);
			obj->force_me("hoho");
		}
	}
	me->start_busy(100);
	obj->start_busy(100);
	call_out("post", 10, me, obj);
}

void post(object me, object obj)
{
	message_vision(HIM"\n$N����$nѩ�׵�Ƥ��������ס�����󶯡�\n\n"NOR,me,obj);
	call_out("sec_post", 3, me, obj);
}

void sec_post(object me, object obj)
{
	message_vision(MAG"\n$N��$n�໥���½�����ߴ������˴���\n\n"NOR, me, obj);
	call_out("trd_post", 10, me, obj);
}

void trd_post(object me, object obj)
{
	message_vision(HIW"\n$N��$n��ӵ���ԣ����Ƹ��꣬��ˮ���죬�������ᣬ����������\n\n"NOR, me, obj);
	call_out("over", 10, me, obj);
}

void over(object me, object obj)
{
        if ( random(10) > 8 && me->query("gender") == "Ů��" && ! obj->query_condition("xu_ruo") ) {
                if ( ! me->query("baby_on") && ! me->query("no_pregnant") ) {
			message_vision(HIC+BLINK"$Nһ����У�����������ҹ�ա���\n\n"NOR, me, obj);
			me->set("preg/id", obj->query("id"));
			me->set("preg/name", obj->query("name"));
			me->set("preg/con", obj->query("con"));
			me->set("preg/int", obj->query("int"));
			me->set("preg/dex", obj->query("dex"));
			me->set("preg/str", obj->query("str"));
			me->set("preg/per", obj->query("per"));
			me->set("preg/pur", obj->query("pur"));
			me->set("preg/kar", obj->query("kar"));
			me->apply_condition("pregnant", 500);
		}
	}
        if ( random(10) > 8 && obj->query("gender") == "Ů��" && ! me->query_condition("xu_ruo") ) {
                if ( ! obj->query("baby_on") && ! obj->query("no_pregnant") ) {
			message_vision(HIC+BLINK"$nһ����У�����������ҹ�ա���\n\n"NOR, me, obj);
			obj->set("preg/id", me->query("id"));
			obj->set("preg/name", me->query("name"));
			obj->set("preg/con", me->query("con"));
			obj->set("preg/int", me->query("int"));
			obj->set("preg/dex", me->query("dex"));
			obj->set("preg/str", me->query("str"));
			obj->set("preg/per", me->query("per"));
			obj->set("preg/pur", me->query("pur"));
			obj->set("preg/kar", me->query("kar"));
			obj->apply_condition("pregnant", 500);
		}
	}
	message_vision(HIM"�����ã�$N��$n����ͣ������������Ȼ�໥η����Ը�ֿ���\n\n"NOR, me,obj);
	if( me->query("qi") < 30 || me->query("jing") < 30 || obj->query("qi") < 30 || obj->query("jing") < 30 ) {
                if( me->query("qi")<30 || me->query("jing") < 30 ) {
			message_vision(HIR "$NͻȻ������Ѫ���ε��ڵء����������������ˡ�\n"NOR,me);
			me->unconcious();
		}
		else {
			message_vision(HIR "$NͻȻ������Ѫ���ε��ڵء����������������ˡ�\n"NOR,obj);
			obj->unconcious();
		}
        }
        else
        switch(random(10)) {
        case 0:
                message_vision(HIR "$NͻȻ���һ������Ȼ�Ǽ����˷ܣ������ž�������ȥ��\n"NOR,me);
                me->unconcious();
                obj->add("qi",obj->query_str()-55+random(10));
                obj->add("jing",obj->query_con()-55+random(10));
                break;
        case 1:
                message_vision(HIR "$NͻȻ���һ������Ȼ�Ǽ����˷ܣ������ž�������ȥ��\n"NOR,obj);
                obj->unconcious();
                me->add("qi",obj->query_str()-55+random(10));
                me->add("jing",obj->query_con()-55+random(10));
                break;
        default:
                if(random(1)) {
                        message_vision(YEL "$N����һ����ͷ�������һ������΢΢������$n��" +
				"��˵����Ҫ��Ȼ������������һ�Ρ���\n\n"NOR, me, obj);
                }
                else {
			message_vision(HIY "$n����������$N�Ļ����������������ţ�" +
				"�����Ǿ��ȵĺ������е����޵��Ҹ�����\n\n"NOR, me, obj);
                }
                obj->add("qi",obj->query_str()-55+random(10));
                obj->add("jing",obj->query_con()-55+random(10));
                me->add("qi",obj->query_str()-55+random(10));
                me->add("jing",obj->query_con()-55+random(10));
        }
	if ( me->query_condition("pregnant") ) {
		me->force_me("cry3");
		me->force_me("say �Ժ���ҳ�ȥ��ô����ѽ����");
	log_file("static/makelove",sprintf("%s(%s)��%s(%s)�Ѷ��Ӹ���ˡ�\n",
		me->name(1),getuid(me),obj->name(1), geteuid(obj)));
	}
	if ( obj->query_condition("pregnant") ) {
		obj->force_me("cry3");
		obj->force_me("say �Ժ���ҳ�ȥ��ô����ѽ����");
	log_file("static/makelove",sprintf("%s(%s)��%s(%s)�Ѷ��Ӹ���ˡ�\n",
		obj->name(1), geteuid(obj),me->name(1),getuid(me)));
	}
	me->start_busy(1);
	obj->start_busy(1);
        me->delete("no_pragnant");
        obj->delete("no_pragnant");
	me->add("makelove", 1);
	obj->add("makelove", 1);
}

int help(object me)
{
	write(@HELP
ָ���ʽ : makelove <����>
������
���֪ʶ�ο����С������������α���������������ʦѰ�ʡ�

HELP);
	return 1;
}
