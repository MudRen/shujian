
int do_zhao(string arg)
{
	object yaocai;
	object me;
	string name;

	me = this_player();
	name = me->query_temp("caiyao_name");

	if (me->is_busy())
		return notify_fail ("�����ں�æ��\n");

	if (me->is_fighting())
		return notify_fail ("�㻹��ר��ս���ɡ���\n");

	if (!( present("yao chu", me)))
		return notify_fail("��������Ѱҩ�ģ�ͻȻ��������ҩ���������������գ���\n");

	if ( !arg || arg != "yaocai" )
		return notify_fail("��Ҫ��ʲô��\n");

	if (! me->query_temp("caiyao_room"))
		return notify_fail("������Щҩ�Ŀ��ǽ�ȱ�쳣����Ͳ�Ҫ��̣�˰ɣ���\n");

	if ( me->query("jingli") < 200)
		return notify_fail ("����ʮ��ƣ������Ҫ�ú���Ϣ�ˣ�\n");

	me->add("jingli",-(60+random(20)));
	message_vision("$N�۹��Ƶ磬Ѹ�ٵ��ڴ�������Ѱ�š�\n", me);

	if( this_object()->query("caiyao_room") < 1 || random(10) < 8 )
		return notify_fail("���Ŀ�Ĺˣ����а��ҩ�ĵ�Ӱ�ӣ����ǵ������ط������ɣ�\n");

	me->delete_temp("caiyao_room");
	me->set_temp("caiyao_ok",1);
	me->add("jingli", -30);
	this_object()->add("caiyao_room", -1);
	message_vision("$N�����ݴԣ�ͻȻ����һ��"YEL+name+NOR",��ϲ��񣬸�æ����ҩ���������������뻳�С�\n",me);
	switch(name) {
		case "����":	yaocai= new(MEDICINE_D("wudang/shengdi"));	break;
		case "����":	yaocai=new(MEDICINE_D("wudang/fuling"));	break;
		case "�컨":	yaocai=new(MEDICINE_D("wudang/honghua"));	break;
		case "����":	yaocai=new(MEDICINE_D("wudang/lingxian"));	break;
		case "����":	yaocai=new(MEDICINE_D("wudang/taoxian"));	break;
		case "ûҩ":	yaocai=new(MEDICINE_D("wudang/meiyao"));	break;
		case "����֬":	yaocai=new(MEDICINE_D("wudang/wulingzhi"));	break;
		case "ǧ����":	yaocai=new(MEDICINE_D("wudang/qianjinzi"));	break;
		case "����":	yaocai=new(MEDICINE_D("wudang/danggui"));	break;
		case "Զ־":	yaocai=new(MEDICINE_D("wudang/yuanzhi"));	break;
		case "����":	yaocai=new(MEDICINE_D("wudang/duhuo"));		break;
		case "����":	yaocai=new(MEDICINE_D("wudang/fangfeng"));	break;
	}
	yaocai->move(me);
	return 1;
}
