// gcreate.c  ����
// by augx@sj 4/11/2002

// Modified by mxzhao 2004/02/18

#include <ansi.h>
inherit F_CLEAN_UP;
#include <mudlib.h>
#include <group.h>

nosave string * valid_group_name = ({ "��","��","��","��","¥","ɽ","��","��","��","��","��","��","��","Ժ","��","԰","��",
				      "��","��","��","��","��","��","Դ","��","ׯ","��","��", "��", "կ", "��","��" });				      
nosave string * invalid_group_name = ({ "ؤ��","�䵱��","������" });
nosave string * invalid_group_id = ({ "obj","npc","entry" });

int help(object me)
{
	write(@HELP
ָ���ʽ :
gcreate [����������(������������)] [����Ӣ�ı�ʾ(3��8��Ӣ����ĸ)]
        [���Եĳ�νһ] [���Եĳ�ν��] [���Եĳ�ν��] [���ڵĳ�ν]

���ָ�����㿪���Լ��İ��ɡ�����������������ĳ�ν�п��Դ���ɫ���ִ���
�������ɫ�ķ�ʽ��nick������ͬ����μ�help nick��
���������������һ���֣���������������֮һ��
    ��ᡢ�š��ɡ�¥��ɽ���̡��ˡ����������ȡ��ݡ�ׯ���š������ꡢ
    �ۡ�Ժ������԰���������á��桢�����¡�Դ�����塢�顢կ���ǡ�
�������ơ�Ӣ�ı�ʾ�������ν������ʹ�ò���(�����ԡ�����)������������
��(��ӹС˵�����е�����)�����֡�����ɾ���˰��ɣ�������������ظ�����
Ӧ����������ĳ�ν����ָ��������������������......

���磺gcreate $YEL$��ͷ�� futou ���� ������ ���� ����
      gcreate $MAG$����$GRN$¥ fengyu $MAG$¥�� ��¥�� ���� ����

HELP
	);
	return 1;
}

int main(object me, string arg)
{
	string gname,gid,gname2,title1,title2,title3,title4;
	int i,j;
       mapping * groups, mp;

	if(!arg || (sscanf(arg,"%s %s %s %s %s %s",gname,gid,title1,title2,title3,title4)<6) )
		return help(me);
		
	if( me->query("registered") < 3 )
		return notify_fail("��Ǹ����ǰֻ��������Ҳ��ܴ������ɣ���μ������� "HIG"help vip"NOR" ���������\n");

	if( me->query("combat_exp") < EXP_REQUIRE )
		return notify_fail("�������̫ǳ������������֯���Լ��İ��ɡ�\n");
	if( me->query("group/class") == 1 )
		return notify_fail("���Ѿ���֯���Լ��İ��ɡ�\n");
	if( me->query("group/id") )
		return notify_fail("���Ѿ������˱�İ��ɡ�\n");



 
	gname = GROUP_D->color_string(gname);
	title1 = GROUP_D->color_string(title1);
	title2 = GROUP_D->color_string(title2);
	title3 = GROUP_D->color_string(title3);
	title4 = GROUP_D->color_string(title4);

	// group name check
	gname2 = strip(gname);
	printf("%s\n",gname2);
	if( (strlen(gname2)%2)==1 || strlen(gname2)<4 || strlen(gname2)>12 || strlen(gid)<4 || strlen(gid)>8 )
		return notify_fail("������������Ӣ�ı�ʶ���Ȳ�����Ҫ����μ�help group��\n");

	for(i=0;i<sizeof(valid_group_name);i++)
		if( gname2[<2..<1] == valid_group_name[i] ) break;
	if( i >= sizeof(valid_group_name) )
		return notify_fail("�������������һ���ֲ�����Ҫ�󣬲μ�help group��\n");

	for(i=0;i<sizeof(invalid_group_name);i++)
		if( gname2 == invalid_group_name[i] ) break;
	if( i < sizeof(invalid_group_name) )
		return notify_fail("�������Ʋ�����Ҫ�󣬲μ�help group��\n");

	// group id check
	for(i=0;i<sizeof(invalid_group_id);i++)
		if( gid == invalid_group_id[i] ) break;
	if( i < sizeof(invalid_group_id) )
		return notify_fail("����Ӣ�ı�ʶ������Ҫ�󣬲μ�help group��\n");





      groups = GROUP_D->get_sort_group();
        for(i=0;i<sizeof(groups);i++) {
      mp = GROUP_D->get_group(groups[i]["id"]);
             if( gname == mp["name"]) j++; 
                                 }
     if(j>=1)
              return notify_fail("��������Ѿ���ʹ���ˣ���������һ������������֡�\n");

     if(GROUP_D->site_now(gid)) 
              return notify_fail("�Ѿ�����������ʹ�ù������ʶ�ˣ���ʹ��glist���鿴����\n");


	me->set("group/id",gid);
	me->set("group/class",1);
	me->save();

	mkdir("/data/npc/group/"+gid);
	GROUP_D->create_group(me,gid,gname,title1,title2,title3,title4);

	tell_object(me,sprintf("�㽨�����Լ��İ��ɣ�%s(%s)��\n",gname,gid));
	CHANNEL_D->do_channel(me,"chat",HIY+RANK_D->query_self(me)+"���տ���"+gname+HIY+"("+gid+")��ϣ����λ�������Ѷ��������"NOR);
	log_file("group/group",sprintf("create :%-12s:%-8s:%-8i:%s(%s)",gname,gid,me->query("combat_exp"),me->name(),me->query("id")),me);

	return 1;
}
