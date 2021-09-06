// danwan.c
// update by lsxk@hsbbs ��������

#define CHANCE 2   //��ͨ�����Ե�������Ʒ�İٷֱ�Ϊ 2%

#include <ansi.h>

inherit ITEM;

string long();

void create()
{
	int i, size;
	string name, id, id1;

	string *first_name=({HIR+"��",YEL+"��",HIY+"��",HIG+"��",HIC+"��",HIB+"��",MAG+"��",HIY+"��",HIW+"��",WHT+"��",HIM+"��",CYN+"��"});
	string *first_id=({"chi","cheng","huang","lv","qing","lan","zi","jin","yin","yu","xian","fei"});
	string *second_name=({"ˮ","��","ʯ","��","ɰ","��","��","��","��","��"});
	string *second_id=({"shui","zhu","shi","ji","sha","lin","long","hu","bao","feng"});
	string *third_name=({"��"+NOR,"��"+NOR});
	string *third_id=({"wan", "dan"});

	size = sizeof(first_name);
	i = random(size);
	name = first_name[i];
	id = first_id[i];

	size = sizeof(second_name);
	i = random(size);
	name += second_name[i];
	id += second_id[i];

	size = sizeof(third_name);
	i = random(size);
	name += third_name[i];
	id1 = third_id[i];

	set_name(name, ({id+" "+id1,id,id1}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", (: long :));
		set("unit", "��");
//           set("no_drop", 1);
//           set("no_give", 1);
		set("sjsz_item", 1);
		set("value", 2000);
	}
	setup();
}

void init()
{
	object me = this_player(), ob;

	if ( environment() == me ) {
		add_action("do_eat", "fu");
		add_action("do_eat", "eat");
	}

	if ( ! query("secret_obj")) return;

	if ( query("owner") == getuid(me) )
		return;

	ob = find_player(query("owner"));

	if ( ! ob) return;

	if ( ob->query_temp("die_by_from") == me){
		ob->delete_temp("die_by_from");
		CHANNEL_D->do_channel( this_object(), "rumor",sprintf("%sŪ����һ��%s��", me->name(1), query("name")));
		set("owner", getuid(me));
		set("eat_time", uptime());
	}
	return;

}

string long()
{
	string str;

	str = query("name")+"("+capitalize(query("id"))+")\n";
	str += "һ��"+query("name")+"������(fu)�Ժ���";
	switch(query("bonus")) {
		case "combat_exp":	str +="����ʵս����";	break;
		case "max_jingli":	str +="��߾���";	break;
		case "max_neili":	str +="�Ӵ�����";	break;
		case "potential":	str +="����Ǳ��";	break;
		default:		str +="һ��";		break;
	}
	str += "�Ĺ�Ч��\n";
	return str;
}

int do_eat(string arg)
{
	object me = this_player();
   object obj;
   int i, max, lvl;
	string str;

	if (!id(arg)) return 0;

	if ( me->is_busy() || me->is_fighting()) 
		return notify_fail("����æ���ء�\n");

	if ( query("owner") != getuid(me))
		return notify_fail("���ʲô�ط��õ��ģ�\n");

	if ( query("secret_obj") && query("eat_time") + 900 > uptime())
		return notify_fail("ʱ��δ���������ڻ����ʺϳԡ�\n");

    //��ӳԳ���ʯ����
  if(this_object()->query("sjsz_item")){
    if(random(100)< CHANCE
     ||(wizardp(me)&&me->query("env/digyu"))){
        message_vision(HIW"$N�շŽ�����һҧ��ֻ�������ԡ�һ����ҧ��һ�����ݣ�\n"NOR,me);
        obj = new("/d/zhiye/obj/othermaterial");
        //����ת���츳����ϵ�ļӳɸ���  by lsxk@hsbbs
        lvl = random(100+(int)me->query("relife/quest/txqr")/2);
        //������1%���ʣ������������Ѷȡ�  by lsxk@hsbbs
        if((!random(115-(int)me->query("relife/quest/txqr"))&&!random(3)) || (wizardp(me) && me->query("env/dig")=="lvl6")){
            obj->set_level(6,random(2)?1:2);
            obj->move(me);
        }
        else if(lvl>90 || (wizardp(me) && me->query("env/dig")=="lvl5")){
            obj->set_level(5,random(2)?1:2);
            obj->move(me);
        }
        else if(lvl>85 || (wizardp(me) && me->query("env/dig")=="lvl4")){
            obj->set_level(4,random(2)?1:2);
            obj->move(me);
        }
        else if(lvl>45 || (wizardp(me) && me->query("env/dig")=="lvl3")){
            obj->set_level(3,random(2)?1:2);
            obj->move(me);
        }
        else{
            obj->set_level(2,random(2)?1:2);
            obj->move(me);
        }
        //�����Խ�ɽׯ������ǡ� by lsxk@hsbbs
        obj->set("sjsz_item",1);
        CHANNEL_D->do_channel( this_object(), "rumor",sprintf("���˿���%s���Խ�ɽׯŪ����һ��%s��", me->name(1), obj->query("name")));
        message_vision(HIR"$N������ġ����衱�ó�������һ�����ҿ���ԭ���ǿ�"HIC"��ʯ"HIR"��\n"NOR,me);
        destruct(this_object());
        return 1;
    }

    //��ӳԳ���ʯ�Ͳ��ϼ���
        if(random(100)< CHANCE || (wizardp(me)&&(me->query("env/digkuang")||me->query("env/digbu")))){
        if(wizardp(me)&&me->query("env/digkuang")){
        message_vision(HIW"$N�շŽ�����һҧ��ֻ�������ԡ�һ����ҧ��һ�����ݣ�\n"NOR,me);
        obj = new("/d/zhiye/obj/kuangshi");
        obj->set("kuang_des",1);
        }
        else if(wizardp(me)&&me->query("env/digbu")){
        message_vision(HIG"$N��ϸ�۲�����ŵ��裬��������Ȼ����������һ�����\n"NOR,me);
        obj = new("/d/zhiye/obj/buliao");
        obj->set("bu_des",1);
        }
        else{
            if(random(2)){
                message_vision(HIW"$N�շŽ�����һҧ��ֻ�������ԡ�һ����ҧ��һ�����ݣ�\n"NOR,me);
                obj = new("/d/zhiye/obj/kuangshi");
                obj->set("kuang_des",1);
                }
                else{
                    message_vision(HIG"$N��ϸ�۲�����ŵ��裬��������Ȼ����������һ�����\n"NOR,me);
                    obj = new("/d/zhiye/obj/buliao");
                    obj->set("bu_des",1);
                }
        }
        lvl = random(100+(int)me->query("relife/quest/txqr")/2);
        if(wizardp(me) && me->query("env/dig")=="lvl11"){
            obj->set_level(11);
            obj->move(me);
        }
        else if(random((lvl>99?100:lvl))>90 || (wizardp(me) && me->query("env/dig")=="lvl10")){
            obj->set_level(10);
            obj->move(me);
        }
        else if((!random(115-(int)me->query("relife/quest/txqr"))&&!random(3)) || (wizardp(me) && me->query("env/dig")=="lvl9")){
            obj->set_level(9);
            obj->move(me);
        }
        else if((lvl>97&&!random(3)) || (wizardp(me) && me->query("env/dig")=="lvl8")){
            obj->set_level(8);
            obj->move(me);
        }
        else if((lvl>96 && !random(2)) || (wizardp(me) && me->query("env/dig")=="lvl7")){
            obj->set_level(7);
            obj->move(me);
        }
        else if(lvl>88 || (wizardp(me) && me->query("env/dig")=="lvl6")){
            obj->set_level(6);
            obj->move(me);
        }
        else if(lvl>70 || (wizardp(me) && me->query("env/dig")=="lvl5")){
            obj->set_level(5);
            obj->move(me);
        }
        else if(lvl>55 || (wizardp(me) && me->query("env/dig")=="lvl4")){
            obj->set_level(4);
            obj->move(me);
        }
        else if(lvl>40 || (wizardp(me) && me->query("env/dig")=="lvl3")){
            obj->set_level(3);
            obj->move(me);
        }
        else if(lvl>20 || (wizardp(me) && me->query("env/dig")=="lvl2")){
            obj->set_level(2);
            obj->move(me);
        }
        else{
            obj->set_level(1);
            obj->move(me);
        }
        //�����Խ�ɽׯ������ǡ� by lsxk@hsbbs
        obj->set("sjsz_item",1);
        if(obj->query("kuang_des")){
            CHANNEL_D->do_channel( this_object(), "rumor",sprintf("���˿���%s���Խ�ɽׯŪ����һ��%s��", me->name(1), obj->query("name")));
            message_vision(HIR"$N������ġ����衱�ó�������һ�����ҿ���ԭ���ǿ�"HIB"��ʯ"HIR"��\n"NOR,me);
        }
        else if(obj->query("bu_des")){
        CHANNEL_D->do_channel( this_object(), "rumor",sprintf("���˿���%s���Խ�ɽׯŪ����һ��%s��", me->name(1), obj->query("name")));
            message_vision(HIR"$N���������С�İ����������⾹Ȼһ��"HIW"����"HIR"��\n"NOR,me);
        }
        destruct(this_object());
        return 1;
    }
  }

	str = HIW"$N����һ��"+query("name")+HIW"����ʱ���û���Ϊ֮һ��������";
	switch(query("bonus")) {
		case "combat_exp":
			if ( query("secret_obj") )
				i = 4000 + random(2000);
			else
				i = 110 + random(80);

                   if(!query("secret_obj") && query("sjsz_item"))
                       i = i * 5 / 2;
			me->add("combat_exp", i);
			log_file("job/shijian", 
				sprintf("%8s%-10sʳ��%6s���õ�%4d�㾭�顣",
					me->name(1),
					"("+getuid(me)+")",
					query("name"),
					i
				), me
			);
			str += chinese_number(i)+"��ʵս���顣\n"NOR;
			break;
		case "max_jingli":
			i = random(2) + 1;
			me->add("max_jingli", i);
			me->add("eff_jingli", i);
			str += chinese_number(i)+"���������\n"NOR;
			break;
		case "max_neili":
			i = random(2) + 1;
			max = (me->query_skill("force")-me->query_temp("apply/force")) * 8 + me->query("combat_exp") / 1000;
			if ( (me->query("max_neili") - 100 ) < max )
				me->add("max_neili", i);
			str += chinese_number(i)+"�����������\n"NOR;
			break;
		case "potential":
			i = random(16) + 22;
			me->add("potential", i);
/*
			if ( me->query("potential") > me->query("max_pot"))
				me->set("potential", me->query("max_pot"));
*/
			str += chinese_number(i)+"��Ǳ�ܡ�\n"NOR;
			break;
		default :
			return notify_fail("�����⣬�������Ա�㱨��\n");
	}
	message_vision(str, me);
	"/adm/daemons/emoted"->do_emote(me,"taste");
	if ( query("secret_obj"))
		CHANNEL_D->do_channel( this_object(), "rumor",sprintf("���˿���%s������һ��%s��", me->name(1), query("name")));
	destruct(this_object());
	return 1;
}
