//�㽶Ƥ
//���ã��ƻ�һЩrobot
//�㽶Ƥֻ��������job����������
//count��ʾ�ƶ��ķ�����Ŀ
//player�п���û�з����ƶ���ԭ����random����ʱ�ֻص������
//Yanqi 10/26/2k

#include <ansi.h>
inherit ITEM;

int flag = 0;

void create()
{
	seteuid(getuid());
	set_name(HIY"�㽶Ƥ"NOR, ({ "xiangjiao pi","pi"}) );
	set("long", "һ���㽶Ƥ��\n");
	set("unit", "��");
	set("value",10);
	set("no_get",1);
	set_weight(5);
	setup();
}

void init()
{
	object me = this_player();
	object env;
//	int i,count = 5;
	int num;
//	mapping exits;
//	string *dirs;

	if( flag ) return;
	if( !me ) return;
	if( wizardp(me) || !userp(me) ) return;
	env = environment();
	if( environment(me) != env ) return;

	if( me->is_busy() || me->is_fighting() || !me->query_conditions_by_type("job") || !me->query("lastroom") ) return;
/*	��ô�ܰ����� move �أ�������� bug
	for (i=0;i<random(count);i++) {
		if (!mapp(exits = env->query("exits"))) return 0;
		dirs = keys(exits);
		if (sizeof(dirs) < 1) return;
		dirs = keys(exits);
		if (!objectp(env = load_object(exits[dirs[random(sizeof(dirs))]]))) return;
	}
*/

	if( random(3) == random(4) ) {
		num = 1+random(me->query("str") * 6 / me->query_dex());
		me->start_busy(num/2);
		message_vision(HIW"\n$Nһ��û���⣬һ�Ų���һ���㽶Ƥ���棬�������һ�����ͷ��\n"NOR,me);
		flag = 1;
		call_out("pa", num - 1, me);
	}
	return;
}

int move(mixed dest, int silently)
{
	flag = 1;
	::move(dest, silently);
	flag = 0;
	return 1;
}

void pa(object me)
{
	flag = 0;
	if( !me ) return;
	message_vision(HIW"����$N������������$N���ò����ƿڴ������˭���㽶Ƥ�������ӣ���\n"NOR, me);

	switch( random(4) ) {
		case 0: {
			message_vision(HIY"$N���㽶Ƥһ�Ÿ��߷��ˡ�\n"NOR,me);
			move(me->query("lastroom"), 1);
			message_vision("$N���˹�����\n",this_object());
		} break;
		case 1: {
			message_vision(HIY"$NԽ��Խ�������˺ݵĶ����㽶Ƥ��ȡ�\n"NOR,me);
			message_vision(HIW"��ˬ��$N����һ�ţ������ϴ���Ƶ�һ�Զ������˳�ȥ��\n"NOR,me);
			destruct(this_object());
		} break;
		case 2: {
			message_vision(HIY"$N���㽶Ƥһ�Ÿ��߷��ˡ�\n"NOR,me);
			move(me->query("lastroom"), 1);
			message_vision("$N���˹�����\n",this_object());
		} break;
		case 3: {
			message_vision(HIY"$N��ͷһ�����������㽶Ƥ�Ѿ����ȵ�û��ģ����\n"NOR,me);
			message_vision(HIW"$N��̬�Ķ��Ų��õ��㽶Ƥ���˼��ڿ�ˮ�������ߵ�һ�ߣ�\n"NOR,me);
			destruct(this_object());
		} break;
        }
}
