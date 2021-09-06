// promote.c
// last modify at 03rd, JUNE 1997 -KEN.Q.Z.ZHANG.
// modify by Looklove because bbb edit err, slogan bbb

#include <ansi.h>

inherit F_CLEAN_UP;

// check the valid levels.
mapping valid_level = ([
	"admin"		:	"(admin)",
	"assist"	:	"(assist)",
	"arch"          :       "(arch)",
	"wizard"        :       "(wizard)",
	"apprentice"    :       "(apprentice)",
	"immortal"      :       "(immortal)",
	"player"        :       "(player)",
]);

int main(object me, string arg)
{
	object ob;
	string old_status, new_status;
	string* rights;
	int i, pass;

	if( me!=this_player(1) ) return 0;

	if( !arg || sscanf(arg, "%s %s", arg, new_status)!=2 )
		return notify_fail("ָ���ʽ��promote <ʹ����> <�ȼ�>\n");

	rights = keys(valid_level);

	// checking the valid levels
	for( i=0; i<sizeof(rights); i++) {
		if( new_status == rights[i] )   {
			new_status = valid_level[rights[i]];
			pass = 1; // valid new level setting.
		}
	}

	// invalid new level setting.
	if( !pass ) return notify_fail("û�����ֵȼ���\n");

        if( !objectp(ob = present(arg, environment(me))) || !userp(ob) )
		return notify_fail("��ֻ�ܸı�ʹ���ߵ�Ȩ�ޡ�\n");

	if( ob == me ) return notify_fail("�㲻�ܸı��Լ���Ȩ�޵ȼ���\n");

	if( wiz_level(me) != wiz_level("(arch)") && wiz_level(me) != wiz_level("(admin)"))
		return notify_fail("��û������Ȩ����\n");

	if( wiz_level(me) <= wiz_level("(arch)") && wiz_level(new_status) >= wiz_level("(arch)") )
		return notify_fail("��û������Ȩ����\n");

	old_status = wizhood(ob);

	if( old_status == new_status )
		return notify_fail(ob->name()+"�Ѿ���"+new_status+"�ˡ�\n");

	seteuid(getuid());
	if( !(SECURITY_D->set_status(ob, new_status)) )
		return notify_fail("�޸�ʧ�ܡ�\n");

	message_vision("$N��$n��Ȩ�޴� " + old_status + " ��Ϊ " + new_status + " ��\n", me, ob);
	log_file( "static/promotion", me->query("name")+"("+me->query("id")+") promoted " +
		ob->query("name") + "(" + ob->query("id") + ") to " + new_status + " on " 
		+ ctime(time()) + "��\n" );
	seteuid(getuid());
	if (!wiz_level(ob)) {
		ob->delete("combat_exp");
		ob->set("str", 20);
		ob->set("int", 20);
		ob->set("con", 20);
		ob->set("dex", 20);
		ob->set("per", 20);
		ob->set("pur", 20);
		ob->set("kar", 20);
	}
	ob->setup();
	ob->save();

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ�� promote ����<id> ����<level>

��������Ȩ�޵ȼ��� player��immortal��apprentice��wizard��
arch��admin��
һ�� admin ������Ȩ�����κεȼ�, �� arch ֻ�������� arch��
HELP );
    return 1;
}
