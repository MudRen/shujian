// nick.c

#include <database.h>
#include <ansi.h>

public string query_version(object ob)
{
	if(ob==find_object(BBS_D)) return "1.0";
}

int main(object me, string arg)
{
	string nickname;
	if( !arg )
		return notify_fail(me->query("nickname")?"��Ŀǰ�Ĵº��ǣ���"+me->query("nickname")+"��\n":"��Ŀǰû���κδºš�\n");
	
	if (arg == "none") {
      		me->delete("nickname");
      		write("���Ĵºű�ɾ���ˡ�\n");
      		if (BBS_D->add_Bbs_Up_Map(WEB_DB_NAME, "UPDATE members SET nickname = 
		'' WHERE username = '"+
		me->query("id")+"@"+lower_case(INTERMUD_MUD_NAME)+"'"))
		
      		write("������̳�Ĵº��Զ�ɾ����\n");
      		return 1;
    	}
    	
    	arg = explode(arg+"\n", "\n")[0];
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);
	if (!strlen(strip(arg))) return notify_fail("�㵽���������ʲô���ݰ���\n");
	if (strlen(strip(arg)) > 24 && !wizardp(me)) return notify_fail("��Ĵº�̫���ˣ���һ����һ��ġ�����һ��ġ�\n");

	me->set("nickname", arg + NOR);
	nickname = specialchars(strip(me->query("nickname")));
	nickname = strip(me->query("nickname"));
	write("��ϲ�������ڵ��´º��ǣ���"+me->query("nickname")+"��\n");
	if (BBS_D->add_Bbs_Up_Map(WEB_DB_NAME, "UPDATE members SET nickname = 
	'"+nickname+"' WHERE username = '"+
	me->query("id")+"@"+lower_case(INTERMUD_MUD_NAME)+"'"))
	/*
	write("UPDATE members SET nickname = 
	'"+strip(me->query("nickname"))+"' WHERE username = '"+
	me->query("id")+"@"+lower_case(INTERMUD_MUD_NAME)+"'\n");
	*/		
	/*BBS_D->add_Bbs_Up_Map(WEB_DB_NAME, "
	INSERT INTO mud_nick (utime, content, name, userid, type, site) 
	values (
	'" + time() +"',
	'" + me->query("nickname") + "',
	'" + me->query("color") + me->query("name") +"',
	'" + me->query("id") + "',
	'nick',
	'"+ lower_case(INTERMUD_MUD_NAME) + "')");*/
	
	write("������̳�Ĵº��Զ����£�\n");
	return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : nick <���>|none
 
���ָ���������Ϊ�Լ�ȡһ�����������Ż�ͷ�Σ�nick none Ϊɾ����
�����ϣ���ڴº���ʹ�� ANSI �Ŀ�����Ԫ�ı���ɫ�����������µĿ����ִ���

HELP
"                        $NOR$ - �ָ�������ɫ\n"
"$RED$ - "RED"��ɫ"NOR"		$HIR$ - "HIR"����ɫ\n"NOR
"$GRN$ - "GRN"��ɫ"NOR"		$HIG$ - "HIG"����ɫ\n"NOR
"$YEL$ - "YEL"����ɫ"NOR"		$HIY$ - "HIY"��ɫ\n"NOR
"$BLU$ - "BLU"����ɫ"NOR"		$HIB$ - "HIB"��ɫ\n"NOR
"$MAG$ - "MAG"ǳ��ɫ"NOR"		$HIM$ - "HIM"�ۺ�ɫ\n"NOR
"$CYN$ - "CYN"����ɫ"NOR"		$HIC$ - "HIC"����ɫ\n"NOR
"$WHT$ - ǳ��ɫ		$HIW$ - "HIW"��ɫ\n"NOR
@HELP 

����ϵͳ�Զ������ִ�β�˼�һ�� $NOR$��
HELP
);
        return 1;
}
