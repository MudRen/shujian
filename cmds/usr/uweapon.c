/*
 * weapon.c
 * ���й�������װ�������
 * Created by snowman@SJ 01/05/2001
 * Last modified by snowman@SJ 25/06/2001
 * Copyright 1997-2004 ShuJian MUD Wizard Group.
 * All rights reserved. 
 */

#include <ansi.h>
#define NAMED		"/adm/daemons/named"

private void confirm_name_again(string yn, object me, object wp, string name,string id);
private void confirm_color(string yn, object me, object wp, string name,string id);
private void confirm_name(string yn, object me, object wp, string name,string id);

nosave string *banned_name = ({
// Mud ��������
"�Լ�","ɱ��","����","ѩ��","��ң","����","����","����","����","���","ĳ��","ʬ��",
"����","�ܹ�","����","����","��ʦ","�ſ�","���","��","�齣","���ִ���","����ͨ","����",
"������","�̿�","����","��ʦ","���","ͷ­","ɱ�˷�","����","���","������","Сɵ��",
// Mud ������������
"��ɽ","��ɽ","��ɽ","��ɽ","̩ɽ","ѩɽ","��ɽ","��ɽ","����","�置","����","��ԭ",
"�Ͻ�","����","�ƺ�","�й�","�л�","����ɽ","����ɽ","����ɽ","�䵱ɽ","����ɽ",
"����","�һ���","��ľ��",
"����","ؤ��","����","����","Ľ��","��Ĺ","ȫ��","����","����","����","�һ�","����",
"������","������","�嶾��","����","а��","��������","�������","�ٸ�","����",
"������","�䵱��","���ư�","��ͨ����","������","����Ľ��","��Ĺ��","��ɽ��","��ɽ��",
"����","������","������",
// ��Ҫ��������
"��ӹ","��Сƽ","������","ë��","���Ż�","�ʵ�","����", "��ϯ",
// С˵����
"������","���޼�","����","���","�����","���","���˷�","ΤС��","Ԭ��־","��һ��",
"�¼���","����","����","�Ƿ�","����","��������","ŷ����","���߹�","��ҩʦ","�λ�ү",
"һ�ƴ�ʦ","������","�ܲ�ͨ","����","������","�������",
// �໰
"ͳһ","����","�����о�","���ִ�","����","�����","ȥ���","������","������","����",
"�쵰","����","ɱ��","����","ǿ��","��Ů","̨��","�쵼","����","ƨ��","ƨ��","����",
"��ƨ","����","����","���","��Ѿ","����","����","����","ɵ��","����","����","�Ҳ�",
"̫��","�¹�","�˸�","����","��", "����", "����", "�ּ�", "��", "����", "����",
//��������
"��Ů","����",
});

nosave string* weapon_list = ({ "sword","axe","blade","brush","club","dagger","fork","hammer","hook","spear","staff","stick","xiao","whip" });

int help(object me);
mapping* get_var(object target)
{
	mapping worker;
	if(mapp(worker = target->query("worker")))
	{
		string *ber;
		string var;
		string type;
		mapping* ret= ({});
		mapping temp = allocate_mapping(5);
		ber = keys(worker);
		for(int i=0;i<sizeof(ber);i++)
		{
//"var" : "armor,��,20325,96800,10,32,1514,zhuma,��Ʒ��β����,2243,2250,,0,0,0,0,0,����Ҫ�����롢��Ʒ��������������ָ�,�߼��÷�  �䵱���(Macwd),,mactz",
//"var" : "whip,8597,0,1,1,17,1947,123,104000,3350,3350,lushi,0,0,0,0,0,������ָ��,�������С���ǿ����,�߼�����ʦ  �䵱���(Macwd),,mactz",
			if(!mapp(worker[ber[i]])) continue;
			var = worker[ber[i]]["var"];
			if(!stringp(var)) continue;
			sscanf(var,"%s,%*s",type);
			sscanf(ber[i],"%s%*d%*s",temp["maker"]);
			
			temp["name"] = "unnamed";
			if(member_array(type,weapon_list) != -1 ) sscanf(var,"%*s,%*d,%*d,%*d,%*d,%*d,%*d,%*d,%*d,%*d,%*d,%*s,%*s,%*d,%*d,%*d,%*d,%s,%*s",temp["name"]);
			else sscanf(var,"%*s,%*s,%*d,%*d,%*d,%*d,%*d,%*s,%s,%*s",temp["name"]);
			
			if( temp["name"] == "unnamed")
			{
				message("wizard:ciwei",sprintf("UweaponϵͳBUG�����㱨��Work:%O,this Var:%s��\n",worker,var),users() );
				continue;
			}
									
			temp["id"]=ber[i];
			temp["type"]=type;
			temp["owner"]=var[strsrch(var,",",-1)+1..<1];
			ret += ({copy(temp)});
		}
		return ret;
	}
	return 0;
}

nosave mapping can_name = ([
	"sword":(["��":"jian","��":"ren",]),
	"xiao":(["��":"xiao",]),
	"axe":(["��":"fu",]),
	"blade":(["��":"dao",]),
	"brush":(["��":"bi",]),
	"club":(["��":"gun",]),
	"dagger":(["ذ":"bi",]),
	"fork":(["��":"cha",]),
	"hammer":(["��":"chui",]),//������Ϸ��� ���������� xixi
	"hook":(["��":"gou",]),
	"spear":(["ǹ":"qiang",]),
	"staff":(["��":"zhang",]),
	"stick":(["��":"bang",]),
	"whip":(["��":"whip","��":"suo"]),
]);
	//�����������ֻ��кܶ�˭����Ȥ�Ͷ�ӵ� xixi

int main(object me, string arg)
{
	int i;
	object wp;	
	string id;
	string name;
	mapping* hehe;
	string* ids =({});

	if (!arg) {
		mapping* t=({});
		string* names=({});
		hehe=get_var(me);
		if ((!hehe||!sizeof(hehe)))
			return notify_fail("��Ŀǰû���Լ���װ����\n");
		//		
		for(i=0;i<sizeof(hehe);i++)
			if(hehe[i]["owner"]==getuid(me)){
				names += ({ hehe[i]["name"] });
				t+= ({ hehe[i]});
			}
		//t=filter_array(hehe, (:$1["owner"]==getuid(me):));
		if(sizeof(t)) write("��Ŀǰ�Ѿ�ӵ����"+chinese_number(sizeof(t))+"��˽��װ����"+ implode(names,",")+"��\n");
		else return notify_fail("��Ŀǰû���Լ���˽��װ����\n");
		return 1;
	}
	
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");
	
	if (sscanf(arg, "delete %s", arg)) {
		if (!objectp(wp = present(arg, me)))
			return notify_fail("������û������װ����\n");		
		if (!wp->query("imbued") || !stringp(id=wp->query("save_id")) )
			return notify_fail("�ⲻ��һ�������װ����\n");
		hehe=get_var(me);
		if(!hehe || !sizeof(hehe)) return notify_fail("�㲢û���Լ���װ����\n");
		for(i=0;i<sizeof(hehe);i++)
			ids += ({ hehe[i]["id"] });
		if(member_array(id,ids)==-1) return notify_fail("�Ⲣ�������װ����\n");
		if(wp->query("owner")!=getuid(me)) return notify_fail("�Ⲣ�������˽��װ����\n");
		
		wp->delete("owner");
		wp->delete("armor_mp/owner");
		wp->delete("weapon_mp/owner");
		/*
		if(strsrch(wp->query("maker"),"/")!=-1)
		{
			wp->set("maker",wp->query("maker")[0..strsrch(wp->query("maker"),"/")-1 ] );
			if(mapp (wp->query("weapon_mp")))
				wp->set("weapon_mp/maker",wp->query("maker"));
			if(mapp (wp->query("armor_mp")))
				wp->set("armor_mp/maker",wp->query("maker"));
		}*/
		
		wp->move(environment(me));
		wp->move(me);
		if(mapp (wp->query("weapon_mp"))) WORKER_D->weapon_rank(wp);
		if(mapp (wp->query("armor_mp"))) WORKER_D->armor_rank(wp);
		write("���Ѿ�ɾ����˽��װ����"+wp->name()+"\n");
		log_file("quest/career/i_delete", sprintf("%s deleted user weapon %s(%d)\n",
				geteuid(me), wp->name(),wp->query("weapon_prop/damage")));
		me->start_busy(1);
		return 1;
	}
	else if (sscanf(arg, "save %s", arg)) {
		mapping worker;
		string type;
		if (!objectp(wp = present(arg, me)))
			return notify_fail("������û������װ����\n");
		if (!wp->query("imbued") || !stringp(id=wp->query("save_id")) )
			return notify_fail(wp->name()+"����һ�������װ����\n");
		
		if(strsrch(id,"weilan tiejiang")==-1) return notify_fail("��Ŀǰֻ�ܱ���Τ�����������װ����\n");
		
		hehe=get_var(me);
		if(!hehe || !sizeof(hehe)) return notify_fail("�㲢û���Լ���װ����\n");
		
		for(i=0;i<sizeof(hehe);i++)
			ids += ({ hehe[i]["id"] });
		
		if(member_array(id,ids)==-1) return notify_fail("�Ⲣ�������װ����\n");
		
		type = wp->query("skill_type");
		if(!type) type = wp->query("armor_type");
		
		ids=({});
		for(i=0;i<sizeof(hehe);i++)
			if(hehe[i]["owner"]==getuid(me))  ids += ({ hehe[i]["type"] });
		
		if(member_array(type,ids)!=-1) return notify_fail("���Ѿ���������ͬ���͵�װ���ˡ�\n");
		
		//if( wizardp(me) || SECURITY_D->get_status(me)!="(player)")
                	//return notify_fail("����ʦû�д����Ȩ��ͬ��ɵ���ʦû�б���װ����Ȩ����\n");
                
                if(mapp(wp->query("weapon_mp"))) type ="weapon";
		else if(mapp(wp->query("armor_mp"))) type ="armor";
		else notify_fail("������󣡣���֪ͨ��ʦ��\n");
		
		if(!mapp(worker = wp->query(type+"_mp"))) return notify_fail("������󣡣���֪ͨ��ʦ��\n");
		
		wp->move(environment(me));
		worker["owner"] = getuid(me);
		//worker["maker"] +=  "/"+me->query("name")+"("+capitalize(getuid(me))+")";
		wp->set(type+"_mp",worker);
		wp->set("owner",getuid(me));
		//wp->set("maker",wp->query("maker")+"/"+me->query("name")+"("+capitalize(getuid(me))+")");
		
		wp->move(me);
		if(type=="weapon") WORKER_D->weapon_rank(wp);
		if(type=="armor") WORKER_D->armor_rank(wp);
		write("\n"+wp->name()+"�������Ѿ�������ϣ���Ϊ��Ŀǰ��˽��װ����\n");
		log_file("quest/career/i_saved", sprintf("%-8s saved user weapon %s(%d).\n",
			geteuid(me), wp->name(), wp->query("weapon_prop/damage") ));
		me->start_busy(1);
		return 1;
	}
	else
	if (sscanf(arg, "rename %s %s", arg, name)==2) {
		mapping mp;
		string type;
		if (!objectp(wp = present(arg, me)))
			return notify_fail("������û������װ����\n");		
		if (!wp->query("imbued") || !stringp(id=wp->query("save_id")) )
			return notify_fail("�ⲻ��һ�������װ����\n");
		hehe=get_var(me);
		if(!hehe || !sizeof(hehe)) return notify_fail("�㲢û���Լ���װ����\n");
		for(i=0;i<sizeof(hehe);i++)
			ids += ({ hehe[i]["id"] });
		if(member_array(id,ids)==-1) return notify_fail("�Ⲣ�������װ����\n");
		if(wp->query("owner")!=getuid(me)) return notify_fail("�Ⲣ�������˽��װ����\n");
		
		if( wp->query("imbued") >= 5 )
			return notify_fail("����װ�������������\n");
		i = (me->query("user_imbue_modify") + 1) * 1000000;
		if (me->query("balance") < i)
			return notify_fail("Ϊװ����������˴���Ҫ"+chinese_number(i/10000)+"���ƽ𣬵���������д�����\n");
		
		i = strlen(name);
		if (i < 4 || i > 8 || i%2)
			return notify_fail("�Բ���װ�����ֱ����� 2 �� 4 �������֡�\n");

		while(i--) {
			if (i%2==0 && !is_chinese(name[i..<1]))
				return notify_fail("�Բ��������á����ġ�ȡװ�����֡�\n");
		}
		
		mp = wp->query("weapon_mp");
				
		if( !mapp(mp) )	{
			return notify_fail("ֻ�������ſ��Ը�����\n");
		}
		
		type = mp["skill_type"];
		if(wp->id("xiao")) type="xiao";
		if( member_array(name[<4..<1],keys(can_name[type]))==-1 && member_array(name[<2..<1],keys(can_name[type]))==-1 )
			return notify_fail(sprintf("���ֵ�����ֱ������װ������ %s ������ֱ���Ϊ��%s ��\n",type,implode(keys(can_name[type]),",") ));
		
		if (member_array(name[0..(strlen(name) - 3)], banned_name)!=-1)
			return notify_fail("����װ�����ֻ���������˵����ţ���������ġ�\n");
		
		
		write(
			"\n�㼴����"+wp->name()+"������\n"
			"�����֣�"+name+"��\n"
			"����װ��ID������� ID + װ�� ID��\n"
			"���η���Ϊ" + chinese_number((me->query("user_imbue_modify") + 1)*100) + "���ƽ�ֱ�Ӵ����д��۳���\n"
			"ȷ����� "HIY"Y"NOR"������ȡ����\n"
		);		
		input_to((: confirm_name :), me, wp, name,undefinedp(can_name[type][name[<4..<1]])?can_name[type][name[<2..<1]]:can_name[type][name[<4..<1]] );		
	}else if(arg == "list")
		me->start_more("/cmds/usr/top.c"->show_worker_rank(me,"weapon",10));
	else if (sscanf(arg, "list %d", i))
		me->start_more("/cmds/usr/top.c"->show_worker_rank(me,"weapon",i?i:10));
	else help(me);
	return 1;
}

private void confirm_name(string yn, object me, object wp, string name,string id)
{
	me->add_busy(1);
	if( yn[0]!='y' && yn[0]!='Y' ) {
		write("��ȡ���˸�˽��װ�������Ĳ�����\n");
	} else {
		write("
���Ѿ�ȷ���������ǡ�"+name+"����������ѡȡ��ɫ��

RED - "RED"��"NOR"��ɫ              HIR - "HIR"��"NOR"����ɫ
GRN - "GRN"��"NOR"��ɫ              HIG - "HIG"��"NOR"����ɫ
YEL - "YEL"��"NOR"����ɫ            HIY - "HIY"��"NOR"����ɫ
BLU - "BLU"��"NOR"����ɫ            HIB - "HIB"��"NOR"����ɫ
MAG - "MAG"��"NOR"ǳ��ɫ            HIM - "HIM"��"NOR"�ۺ�ɫ
CYN - "CYN"��"NOR"����ɫ            HIC - "HIC"��"NOR"����ɫ
WHT - "WHT"��"NOR"��ɫ              HIW - "HIW"��"NOR"����ɫ

�������Ҫ��ɫ����� "HIY"Y"NOR"������ȡ����\n");
		input_to((: confirm_color :), me, wp, name,id);
	}
}

private void confirm_color(string yn, object me, object wp, string name,string id)
{
	string color;

	me->add_busy(1);

	switch (yn) {
		case "RED" : color = RED; break;
		case "GRN" : color = GRN; break;
		case "YEL" : color = YEL; break;
		case "BLU" : color = BLU; break;
		case "MAG" : color = MAG; break;
		case "CYN" : color = CYN; break;
		case "WHT" : color = WHT; break;
		case "HIR" : color = HIR; break;
		case "HIG" : color = HIG; break;
		case "HIY" : color = HIY; break;
		case "HIB" : color = HIB; break;
		case "HIM" : color = HIM; break;
		case "HIC" : color = HIC; break;
		case "HIW" : color = HIW; break;
		case "y":
		case "Y": write("���ٴ�ȷ���Ƿ��װ��������ȷ�����"WHT" Y"NOR"�����������ȡ����\n");
			input_to( (: confirm_name_again :), me, wp, name,id );
			return;
		default :
			write("\n��û��������ɫ������ȡ���˸�˽��װ�������Ĳ�����\n");
			return;
	}
	name = color + name;
	write(
		"\n��Ϊװ��ѡ����"+color+"��"NOR"���Ƿ�ȷ��������\n"
		"��ѡ�� "HIY"Y"NOR"���������ȡ����\n"
	);
	input_to( (: confirm_name_again :), me, wp, name ,id);
}

private void confirm_name_again(string yn, object me, object wp, string name,string id)
{
	mapping mp;
	string *ids;
	string* newids;
	int i;
	int need_add=0;

	if( yn[0]!='y' && yn[0]!='Y' ) {
		write("��ȡ���˸�˽��װ�������Ĳ�����\n");
	} else {
		mp = wp->query("weapon_mp");				
		if( !mapp(mp) )	{
			write("ֻ��װ���ſ��Ը�����\n");
			return;
		}
		name += NOR;
		
		ids = mp["id"];
		newids = ({geteuid(me) + " " + id});
		for(i=0;i<sizeof(ids);i++)
			if( strsrch(ids[i]," ")==-1)
			{
				newids+= ({ids[i]});
				if(ids[i]==id) need_add=1;
			}
		if(!need_add) newids+= ({id});
		
		i = (me->query("user_imbue_modify") + 1) * 1000000;
		me->add("balance", -i);
		me->add("user_imbue_modify", 1);
		
		log_file("quest/career/i_rename", sprintf("%-8s used %d gold rename %s with %s.\n",
			geteuid(me), i/10000, mp["name"], name,));
		
		//ids[0] = geteuid(me) + " " + ids[2];
		//ids[1] = geteuid(me) + " " + ids[3];
		mp["id"] = newids;
		mp["name"] = name;
		
		wp->set_name(name, newids);				
		wp->move(environment(me));
		wp->move(me);
		wp->set_name(name, newids);		
		if(mapp (wp->query("weapon_mp"))) WORKER_D->weapon_rank(wp);
		if(mapp (wp->query("armor_mp"))) WORKER_D->armor_rank(wp);
				
		write("�㻨��" + chinese_number(i/10000) + "���ƽ����װ�����֣��µ�װ�����֣�" + name + " ��\n");
	}
	me->add_busy(1);
}


int help(object me)
{
	write(@HELP
ָ���ʽ : uweapon save|delete

���ָ��������㴢���ɾ���Լ���˽��װ����

����:  	�� uweapon save <װ��>
	ȷ�Ϻ󣬴�װ�����Ϊ��˽�����У���ʹ��ʧ�´ε�½Ҳ�������������ϡ�

	�� uweapon delete <װ��>
	ȷ�Ϻ����˽��װ����־�������
	
	�� uweapon rename <װ��> <����>
	Ϊ�Լ���װ��������

        �� uweapon list <����>
        �鿴��ǰװ��������
	

ע�⣺���Ŀǰ��Ϸ�������װ������¼ʱ�㲻������������ϡ�
      Ŀǰֻ�ܱ���Τ������Ϊ�������ı�����

   Copyright 1996-2004 ShuJian MUD Wizard Group.
   All rights reserved.
HELP
);
    return 1;

}