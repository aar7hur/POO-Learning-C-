class Decision{
	private:
		bool purchaseAction;
		struct decisionData{
			float closeWeek;
			float average_20;
			float average_50;
			float stochastic_8;
		};
		struct dataRisk{
			float highDaily;
			float lowDaily;
		};
		//bool ispurchaseAction()
	public:
		void populateData(void);
		Decision();
		~Decision();	
};

