inherit ROOM;

void create()
{
	set("short", "�����ɴ�");
	set("long", @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ����ʮ������������ֳ�һ����
��ݣ����ڴ�β�����س��Ŵ���
LONG);
	set("no_fight", 1);
	set("outdoors", "����");
	set("no_sleep_room", 1);
	setup();
}

int arrive(string arg)
{
	object room, ob = this_object();

	set("start", 1);
	if (stringp(arg)) set("side", arg);
	if (room = load_object(__DIR__ + query("side"))) {
		tell_room(ob, "\n�ɴ��͵�һ���Ѿ�����������˵������������´��ɣ���\n");
		set("exits/out", __DIR__+ob->query("side"));
		tell_room(ob, "˵�Ž�һ��̤�Ű���ϵ̰����γ�һ����ȥ(out)�Ľ��ݡ�\n");
		room->set("exits/enter", __FILE__);
		tell_room(room, "\nһ�Ҷɴ�������ʻ�˹�����������һ��̤�Ű���ϵ̰����Ա�˿�����(enter)��\n");
		remove_call_out("on_board");
	  	call_out("on_board", 25);
	}
	return 1;
}

void on_board()
{
	object room, *obj, ob = this_object();
	int i;

	ob = this_object();

	if (room = load_object(__DIR__ + query("side"))) {
		obj = all_inventory(ob);
		for(i = 0; i < sizeof(obj); i++) {
			if (userp(obj[i]) && obj[i]->query_temp("side") != ob->query("side")) {
				if (!living(obj[i])) tell_room(ob, "������"+obj[i]->name()+"̧���˴���\n");
				else tell_room(ob, obj[i]->name()+"���������Ļ����ԹԵ����˴���\n", obj[i]);
				obj[i]->move(room);
				obj[i]->delete_temp("side");
				if (!living(obj[i])) tell_room(room, obj[i]->name() + "��̧���˴���\n", obj[i]);
				else tell_room(room, obj[i]->name() + "�����˴���\n", obj[i]);
			}
		}
		room->delete("exits/enter");
		tell_room(room, "\n�����ǰ�̤�Ű���������������һ�㣬�ɴ�����ʻȥ��\n");
	}
	delete("exits/out");
	tell_room(ob, "\n�����ǰ�̤�Ű���������˵��һ��������ඡ�������һ�㣬�ɴ�����ʻȥ��\n");
	set("start", 2);
	if (query("side") == "jiangbei2") set("side", "jiangnan2");
	else set("side", "jiangbei2");
	remove_call_out("arrive");
	call_out("arrive", 10+random(5));
}
