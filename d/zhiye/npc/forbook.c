// forbook.c

// Modified by mxzhao 2004/03/06 caijian => zhizao

#include <ansi.h>
#define MAX_SKILLS 15

string getscore(string* vb);

nosave string *weapon_list =
        ({"sword","axe","blade","brush","club","dagger","fork","hammer","hook","spear","staff","stick","xiao","whip","arrow"});
nosave string *armor_list =
	({"cap","boot","coat","armor","mantle","belt","glove",});
nosave string *all_list =
        ({"sword","axe","blade","brush","club","dagger","fork","hammer","hook","spear","staff","stick","xiao","whip","arrow",
	"cap","boot","coat","armor","mantle","belt","glove",
	});
nosave mapping get_chinese = ([
	"axe":"��",
	"brush":"��",
	"fork":"��",
	"hook":"��",
        "spear":"ǹ", 
//        "arrow":"��", 
	"whip":"��",
	"stick":"��",
	"sword":"��",
   "xiao":"��",
	"blade":"��",
	"dagger":"ذ��",
	"club":"��",
	"staff":"��",
	"hammer":"����",
	"throwing":"����",
	"cap":"ͷ��",
	"glove":"����",
	"boot":"ѥ",
	"belt":"����",
	"mantle":"����",
	"coat":"����",
	"armor":"����",
	"cloth":"�·�",
	"finger":"��ָ",
	"neck":"����",	
	"wrists":"����",	
	"hands":"ָ��",
	"mineral":"��ʯ",
	"jade":"��",
	"silk":"˿",
	"cloths":"��",
]);

string getscore(string* vb)
{
	int i;
	string str;
	
	if(!arrayp(vb)) return "";
	i = sizeof(vb);	
	if (i<=0) str = HIY "��Ŀǰ�����κι������ܡ�\n"NOR;
	else {
		str = HIY"���Ѿ�ѧ����";
		while(i--)
			str +=get_chinese[vb[i]]+"("+capitalize(vb[i])+")��";
		str += "�Ĺ���������\n"NOR;
		str = replace_string(str,"����","��");
	}	
	return str;	
}

int accept_object(object who, object ob, object me){
	string title;
	string *vb = ({});
	mapping myskill;
	string skill,skill_name;	
	int i;
	
	me = this_object();
	if(me->id("zhujian shi") && ob->query("dazao_award") && ob->id("weilan's hammer"))
	{
		command("ah");
		command("thank "+getuid(who));
		command("whisper "+getuid(who)+" ��Ҳ����ʲô������ʾ������Τ���ٰ������һ�ΰɡ�");
		call_out("destroying", 1, ob);
		who->add("imbue_reward",1);
		return 1;
	}
	if(!stringp(me->query("forg_type"))) return 0;
	if(me->query("forg_type")!="weapon" && me->query("forg_type")!="armor" && me->query("forg_type")!="all" ) return 0;
	if(me->query("forg_type")=="weapon"){
		skill = "duanzao";
		skill_name = "����";
		vb = weapon_list;
	}
	else if(me->query("forg_type")=="armor"){
		skill = "zhizao";
		skill_name = "֯��";
		vb = armor_list;
	}
	else if(me->query("forg_type")=="all"){
		skill = "";
		skill_name = "����";
		vb = all_list;
	}
	if (skill=="" && ob->query("name") == HIW"��������"NOR && me->query("id")=="han tiejiang" && !mapp(who->query("forging")))
	{
		message_vision("$N���´�����$n���ۡ�\n$N��Ȼ��̾������ʮ������������֮�����ѷ�����֮������������ͷȴ���ڽ̵��޶�����ݿ������������簡����\n",
		me,who);
		command("say ����ˣ��Ҿʹ����޶���һЩ����֮����");
		title = "����֮����������ԯ�������и���Ϊ";
		for(i=0;i<sizeof(vb);i++)
			title += get_chinese[vb[i]]+"("+vb[i]+") ";
		title +="��";
		command("say "+title);
		tell_object(who, YEL "������taojiao ��ش��켼�ܵ����Ĵ��� from id ��ѧϰ����Ҫ�Ĺ���֮����\n"NOR);
		tell_object(who, YEL "������Ҫѧϰ���콣�����������taojiao sword from han��\n"NOR);
		who->set("dazao/give",1);//�������������ʧ���ĳ����ñ���
		call_out("destroying", 1, ob);
		return 1;
	}	
	else if ( ob->query("for_forg") ){
	command("look "+who->query("id",1));
	if (who->query("dazao/give")){
		command("say ��СС��ͣ������ҵ��ܶ�ö�����������ǰһ�λ��ỹû�õ��أ�");
		command("say �����õ���(taojiao ***)�ٸ��Ұɣ�");
		return 0;
	}
	
	title = skill_name+"֮����������ԯ�������и���Ϊ";
	for(i=0;i<sizeof(vb);i++)
		title += get_chinese[vb[i]]+"("+vb[i]+") ";
	title +="��";
	command("say "+title);
			
	myskill = who->query("forging");
	if(!mapp(myskill)) myskill =([]);
	vb= keys(myskill);
	i = sizeof(vb);
	if (!mapp(myskill)) i = 0;
	
	if ( who->query_skill(skill,1) / 30 <= i && who->query_skill(skill,1)!=0 ){
	command("say ������"+skill_name+"��ѧ�ղ������ٶ����Ҳû���ã������Ȼ�ȥ�ɣ�����"+skill_name+"����ʱ���Ҳ��٣�");
	return 0;
	}		
	command("say û�뵽����������ǰ���ؼ���������ϣ���Ҳ���ܰ����㣬���ǿ�һ�����"+skill_name+"���ϳ˼�����");

	switch(i){
		case 0:
		command("say "+RANK_D->query_respect(who)+"����"+skill_name+"֮��ֻ֪һ��ȴ��Ե�ô˱��飬ʵ�˸�����񰡡�");
		break;
		case 4:
		command("say "+RANK_D->query_respect(who)+skill_name+"�����Ѿ�¯����,���Ŵ���������һ��֮����");
		break;
		case 8:
		command("say "+RANK_D->query_respect(who)+"�Ѿ����ϴ˵����ô���������绢����");
		command("tsk "+who->query("id",1));
		break;
		case 12:
		command("say "+RANK_D->query_respect(who)+"����֮�ɾͿ�׷����ɽ�Īа��");
		command("flatter "+who->query("id",1));
		break;
		case MAX_SKILLS:
		command("say "+RANK_D->query_respect(who)+"������֮�У�������Ҳ�ò����ˡ�");
		title = "�� " + who->query("name") + "(" + capitalize(who->query("id")) + ")";
		who->set_temp("apply/short", ({title}));
		return 0;
		default:
		command("say ϣ��"+RANK_D->query_respect(who)+"�ú���ϰ���飬�պ�صô���");
		command("addoil "+who->query("id",1));
	}
	command("say �����Ǿ��ֽ�һ���й�"+skill_name+"֮����!");
	tell_object(who,getscore(vb));
	tell_object(who, YEL "������taojiao ��ش��켼�ܵ����Ĵ��� from id ��ѧϰ����Ҫ��"+skill_name+"֮����\n"NOR);
	//tell_object(who, YEL "������Ҫѧϰ���콣�����������taojiao sword��\n"NOR);
	who->set("dazao/give",1);
	call_out("destroying", 1, ob);
	return 1;
	}
       message_vision(CYN "$N" CYN "��$n" CYN "�ݹ�ȥ��" + ob->name() +
                                       CYN "���˻�����ҡͷ�����޹�����»��\n" NOR,
                                       this_object(), who);
	return 0;
}

int do_taojiao(string arg)
{
	object me;
	string *vb;
	object ob;
	mapping myskill;	
	string skill,skill_name;
	string sf;
	int i;
	
	me = this_object();	
	
	if(!stringp(me->query("forg_type"))) return 0;		
	if(me->query("forg_type")!="weapon" && me->query("forg_type")!="armor" && me->query("forg_type")!="all" ) return 0;
	if(me->query("forg_type")=="weapon"){
		skill = "duanzao";
		skill_name = "����";
		vb = weapon_list;
	}
	else if(me->query("forg_type")=="armor"){
		skill = "zhizao";
		skill_name = "֯��";
		vb = armor_list;
	}
	else if(me->query("forg_type")=="all"){
		skill = "";
		skill_name = "����";
		vb = all_list;
	}
	
	me = this_player();	
	if( !me->query("dazao/give")) return 0;
	myskill = me->query("forging");
	if(!mapp(myskill)) myskill=([]);
	if( !arg || sscanf(arg,"%s from %s",arg,sf) !=2 || !sf)
		return notify_fail("��Ҫ��˭�ֽ�ʲô��\n");	
	if(!objectp(ob = present(sf,environment(me))))
		return notify_fail("����û����ˡ�\n");
	if(ob->parse_command_id_list()[0] != this_object()->parse_command_id_list()[0]) return 0;
	//if ((int)me->query_skill(skill,1) < 10){
		//command("say "+RANK_D->query_self(this_object())+"����ѧϰ������Ŀ��������Ҫ"+skill_name+"��ʮ����");
		//return 1;
	//}
	if( !arg || arg=="" ) {
		arg = skill_name+"֮����������ԯ�������и���Ϊ";
		for(i=0;i<sizeof(vb);i++)
			arg += get_chinese[vb[i]]+"("+vb[i]+") ";
		arg +="��";
		command("say "+arg);
		command("say �����Ǿ��ֽ�һ���й�"+skill_name+"֮����!");
		vb = keys(myskill);
		tell_object(me,getscore(vb));
		tell_object(me, YEL "������taojiao ��ع������ܵ����Ĵ��� from id ��ѧϰ����Ҫ��"+skill_name+"֮����\n"NOR);
		//tell_object(me, YEL "������Ҫѧϰ���콣�����������taojiao sword��\n"NOR);
		return 1;
	}
	
	if( member_array(arg,vb) == -1 ){
	command("ah");
	return notify_fail(this_object()->name()+"�����ǵ��Ƿ��д˼�������\n");
	}
	if (mapp(myskill)){
		vb = keys(myskill);
		if( member_array(arg,vb) != -1 ){
		command("shake");
		return notify_fail("���Ȼ�Ѿ�ѧ��˼����α��˷ѻ����أ�\n");
		}
		
		if (skill!="" && me->query_skill(skill,1) / 30 <= sizeof(vb) ){
		command("say ��"+skill_name+"֮��ѧ�ղ������ٶ����Ҳû���ã������Ȼ�ȥ�ɣ���λ����Ҹ��㱣���ţ�����"+skill_name+"֮����ʱ���Ҳ��٣�");
		//command("say ���ҿ�����Ŀǰ�ļ���������ѧ"+HIY+chinese_number(me->query_skill("forging",1) / 30)+NOR+"�������Ŀ");
		return 1;
		}
	}
	command("ok");	
	if(skill!="") WORKER_D->check_impove(me,skill,me->query_skill(skill,1)*me->query_skill(skill,1),2);	
	me->set("forging/"+arg,1);
	me->delete("dazao/give");
	if(stringp(get_chinese[arg])) arg = get_chinese[arg];
	message_vision("$N��$n��ϸ�ֽ����й�"+HIY+arg+NOR+"����Ĵ���֪ʶ��\n",me,  this_object());
	tell_object(me, WHT "��ѧ���˵�"+HIY+arg+WHT+"�������֪ʶ���о��Լ���"+skill_name+"��Ҳ������ߡ�\n"NOR);
	return 1;
}
